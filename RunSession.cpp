#include "RunSession.h"
#include <iostream>

using namespace std;

RunSession::RunSession(unsigned int seed) : rng(seed) {}

void RunSession::GenerateDeck() {
}

void RunSession::ChooseHand() {
}

void RunSession::PrintHand() const {
}

bool RunSession::CheckWin(int score) const {
}

int RunSession::ComputeCashReward(int score, bool win) const {
}

void RunSession::Start() {
    GenerateDeck();
};