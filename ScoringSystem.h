#pragma once
#include <vector>
#include <memory>
#include "Hand.h"
#include "modifiers/IModifier.h"

using namespace std;

class ScoringSystem {
public:
    int ScoreHand(const Hand& hand, const vector<unique_ptr<IModifier>>& modifiers) const;

private:
    int ComputeBaseChips(const Hand& hand) const;
};#pragma once
