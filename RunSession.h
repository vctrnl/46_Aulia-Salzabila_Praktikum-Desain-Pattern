#include <vector>
#include <memory>
#include <random>
#include "Deck.h"
#include "Hand.h"
#include "ScoringSystem.h"
#include "ShopSystem.h"
#include "modifiers/IModifier.h"

using namespace std;

class RunSession {
public:
    explicit RunSession(unsigned int seed = 12345);

    void Start();

private:
    void GenerateDeck();
    void ChooseHand();
    void PrintHand() const;

    bool CheckWin(int score) const;
    int ComputeCashReward(int score, bool win) const;

private:
    mt19937 rng;
    Deck deck;
    Hand hand;

    ScoringSystem scoring;
    ShopSystem shop;

    int cash = 50;
    int targetScore = 120;

    vector<unique_ptr<IModifier>> modifiers;
};