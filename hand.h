#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class Hand {
public:
    void Clear();
    void Add(const Card& c);

    const vector<Card>& Cards() const;

private:
    vector<Card> cards;
};
