#pragma once
#include <vector>
#include <memory>
#include <random>
#include "Deck.h"
#include "Hand.h"

using namespace std;

class RunSession {
public:
    explicit RunSession(unsigned int seed = 12345);

    void Start();

private:
    void GenerateDeck();
    void ChooseHand();
    void PrintHand() const;
};