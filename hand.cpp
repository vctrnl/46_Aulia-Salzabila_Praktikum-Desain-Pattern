#include "Hand.h"

using namespace std;

void Hand::Clear() {
    cards.clear();
}

void Hand::Add(const Card& c) {
    cards.push_back(c);
}

int Hand::Size() const {
    return static_cast<int>(cards.size());
}

const vector<Card>& Hand::Cards() const {
    return cards;
}

void Hand::ValidatePlay(const vector<int>& indices) const {
    if (indices.empty()) throw invalid_argument("Tidak ada kartu yang dipilih");
    if (static_cast<int>(indices.size()) > MAX_PLAY) throw invalid_argument("Maksimal 5 kartu dimainkan");
    if (indices.size() > cards.size()) throw invalid_argument("Pilihan melebihi jumlah kartu di tangan");

    vector<int> temp = indices;
    sort(temp.begin(), temp.end());

    for (size_t i = 0; i < temp.size(); ++i) {
        if (temp[i] < 0 || temp[i] >= static_cast<int>(cards.size())) {
            throw out_of_range("Index kartu tidak valid");
        }
        if (i > 0 && temp[i] == temp[i - 1]) {
            throw invalid_argument("Index kartu tidak boleh duplikat");
        }
    }
}

vector<Card> Hand::PlaySelected(const vector<int>& indices) {
    ValidatePlay(indices);

    vector<int> temp = indices;
    sort(temp.begin(), temp.end(), greater<int>());

    vector<Card> played;
    played.reserve(temp.size());

    for (int idx : temp) {
        played.push_back(cards[idx]);
        cards.erase(cards.begin() + idx);
    }

    reverse(played.begin(), played.end());
    return played;
}