#include "RunSession.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

RunSession::RunSession(unsigned int seed) : rng(seed) {
    deck.GenerateStandard52();
    deck.Shuffle(rng);
}

void RunSession::PrepareDeckIfNeeded(int needCards) {
    if (deck.Size() >= needCards) return;
    deck.GenerateStandard52();
    deck.Shuffle(rng);
}

void RunSession::DealNewHand() {
    PrepareDeckIfNeeded(HAND_SIZE);
    hand.Clear();
    for (int i = 0; i < HAND_SIZE; ++i) {
        hand.Add(deck.Draw());
    }
}

void RunSession::PrintCurrentHand() const {
    cout << "Kartu di tangan:\n";
    const auto& v = hand.Cards();
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << i << ": " << v[i].ToString() << "\n";
    }
}

vector<int> RunSession::ReadPlayIndices() const {
    while (true) {
        cout << "Pilih index kartu (maks 5), pisah spasi. Contoh: 0 2 5 7\n";
        cout << "Input: ";

        string line;
        getline(cin, line);
        if (line.empty()) {
            cout << "Input kosong.\n";
            continue;
        }

        istringstream iss(line);
        vector<int> idx;
        int x;

        while (iss >> x) idx.push_back(x);

        if (idx.empty()) {
            cout << "Tidak ada angka.\n";
            continue;
        }

        if ((int)idx.size() > Hand::MAX_PLAY) {
            cout << "Maksimal 5 kartu.\n";
            continue;
        }

        return idx;
    }
}

string RunSession::HandTypeToString(ScoringSystem::HandType t) const {
    switch (t) {
    case ScoringSystem::HandType::HighCard: return "HighCard";
    case ScoringSystem::HandType::Pair: return "Pair";
    case ScoringSystem::HandType::TwoPair: return "TwoPair";
    case ScoringSystem::HandType::ThreeKind: return "ThreeKind";
    case ScoringSystem::HandType::Straight: return "Straight";
    case ScoringSystem::HandType::Flush: return "Flush";
    case ScoringSystem::HandType::FullHouse: return "FullHouse";
    case ScoringSystem::HandType::FourKind: return "FourKind";
    case ScoringSystem::HandType::StraightFlush: return "StraightFlush";
    }
    return "Unknown";
}

void RunSession::Start() {
    while (true) {
        cout << "\n=== ROUND " << roundIndex << " ===\n";
        cout << "Target score: " << targetScore << "\n";

        int handsLeft = HANDS_PER_ROUND;
        int roundScore = 0;

        while (handsLeft > 0) {
            cout << "\nHand tersisa: " << handsLeft << "\n";
            cout << "Score saat ini: " << roundScore << "\n";

            DealNewHand();
            PrintCurrentHand();

            vector<int> pick = ReadPlayIndices();

            vector<Card> played;
            try {
                played = hand.PlaySelected(pick);
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
                continue;
            }

            auto bs = scoring.EvaluateBase(played);
            cout << "Combo: " << HandTypeToString(bs.type) << "\n";
            cout << "Chips: " << bs.chips << " Mult: " << bs.mult << "\n";
            cout << "Score hand: " << bs.finalScore << "\n";

            roundScore += bs.finalScore;

            if (roundScore >= targetScore) {
                cout << "MENANG ROUND.\n";
                break;
            }

            handsLeft -= 1;
        }

        if (roundScore < targetScore) {
            cout << "GAME OVER. Kamu gagal capai target.\n";
            break;
        }

        targetScore += 30;
        roundIndex += 1;

        cout << "Lanjut round? (y/n): ";
        char ans = 'y';
        cin >> ans;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!(ans == 'y' || ans == 'Y')) break;
    }
}