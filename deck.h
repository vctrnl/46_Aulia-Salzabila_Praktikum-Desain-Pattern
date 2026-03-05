#pragma once
#include <vector>
#include <random>
#include "Card.h"

using namespace std;

class Deck {
public:
    void GenerateStandard52();
    void Shuffle(mt19937& rng);

    Card Draw();
    bool Empty() const;
    int Size() const;

private:
    vector<Card> cards;
};
