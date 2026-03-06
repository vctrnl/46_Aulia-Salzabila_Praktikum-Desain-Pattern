#pragma once
#include <random>
#include <vector>
#include <string>
#include "Deck.h"
#include "Hand.h"
#include "ScoringSystem.h"

using namespace std;

class RunSession {
public:
    RunSession();                      // seed random, tiap program run beda
    explicit RunSession(unsigned int seed);

    void Start();

private:
    static const int HAND_SIZE = 8;
    static const int HANDS_PER_ROUND = 4;

    void PrepareDeckIfNeeded(int needCards);
    void DealNewHand();
    vector<int> ReadPlayIndices() const;
    void PrintCurrentHand() const;
    string HandTypeToString(ScoringSystem::HandType t) const;

private:
    mt19937 rng;
    Deck deck;
    Hand hand;
    ScoringSystem scoring;

    int targetScore = 120;
    int roundIndex = 1;
};