#include "Card.h"

using namespace std;

static const char* SuitStr(Suit s) {
    switch (s) {
    case Suit::Hearts: return "H";
    case Suit::Diamonds: return "D";
    case Suit::Clubs: return "C";
    case Suit::Spades: return "S";
    }
    return "?";
}

static const char* RankStr(Rank r) {
    switch (r) {
    case Rank::Two: return "2";
    case Rank::Three: return "3";
    case Rank::Four: return "4";
    case Rank::Five: return "5";
    case Rank::Six: return "6";
    case Rank::Seven: return "7";
    case Rank::Eight: return "8";
    case Rank::Nine: return "9";
    case Rank::Ten: return "10";
    case Rank::Jack: return "J";
    case Rank::Queen: return "Q";
    case Rank::King: return "K";
    case Rank::Ace: return "A";
    }
    return "?";
}

string Card::ToString() const {
    return string(RankStr(rank)) + SuitStr(suit);
}