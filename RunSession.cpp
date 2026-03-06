#include "RunSession.h"
#include <iostream>

using namespace std;

RunSession::RunSession(unsigned int seed) : rng(seed) {}

void RunSession::GenerateDeck() {
    deck.GenerateStandard52();
    deck.Shuffle(rng);
}

void RunSession::ChooseHand() {
    hand.Clear();
    for (int i = 0; i < 5; ++i) {
        hand.Add(deck.Draw());
    }
}

void RunSession::PrintHand() const {
    cout << "Hand: ";
    for (const auto& c : hand.Cards()) {
        cout << c.ToString() << " ";
    }
    cout << "\n";
}

bool RunSession::CheckWin(int score) const {
    return score >= targetScore;
}

int RunSession::ComputeCashReward(int score, bool win) const {
    int base = score / 10;
    if (win) base += 10;
    if (base < 0) base = 0;
    return base;
}

void RunSession::Start() {
    GenerateDeck();

    bool running = true;
    int round = 1;

    while (running) {
        cout << "\n=== ROUND " << round << " ===\n";
        cout << "Target: " << targetScore << "\n";
        cout << "Cash: " << cash << "\n";

        if (deck.Size() < 5) {
            cout << "Running out of deck cards. Regenerate deck.\n";
            GenerateDeck();
        }

        ChooseHand();
        PrintHand();

        int score = scoring.ScoreHand(hand, modifiers);
        cout << "Score: " << score << "\n";

        bool win = CheckWin(score);
        cout << (win ? "WIN\n" : "LOSE\n");

        int reward = ComputeCashReward(score, win);
        cash += reward;
        cout << "Reward cash: " << reward << "\n";

        if (!win) {
            cout << "Round ended.\n";
            break;
        }

        shop.EnterShop(cash, modifiers, rng);

        targetScore += 30;
        round += 1;

        cout << "Proceed to next round? (y/n): ";
        char ans = 'y';
        cin >> ans;
        if (!(ans == 'y' || ans == 'Y')) running = false;
    }
}