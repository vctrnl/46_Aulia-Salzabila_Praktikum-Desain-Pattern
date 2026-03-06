#pragma once
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
    explicit RunSession(unsigned int seed = 12345);

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