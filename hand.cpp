// src/Hand.cpp
#include "Hand.h"

using namespace std;

void Hand::Clear() { cards.clear(); }
void Hand::Add(const Card& c) { cards.push_back(c); }
const vector<Card>& Hand::Cards() const { return cards; }