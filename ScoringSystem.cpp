#include "ScoringSystem.h"

using namespace std;

int ScoringSystem::ComputeBaseChips(const Hand& hand) const {
    int chips = 0;
    for (const auto& c : hand.Cards()) {
        chips += static_cast<int>(c.rank);
    }
    return chips;
}

int ScoringSystem::ScoreHand(const Hand& hand, const vector<unique_ptr<IModifier>>& modifiers) const {
    ScoreContext ctx;
    ctx.baseChips = ComputeBaseChips(hand);
    ctx.baseMult = 1;

    for (const auto& m : modifiers) {
        if (m) m->Apply(ctx);
    }

    ctx.finalScore = ctx.baseChips * ctx.baseMult;
    return ctx.finalScore;
}