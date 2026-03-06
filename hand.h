#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Card.h"

using namespace std;

class Hand {
public:
    static const int MAX_PLAY = 5;

    void Clear();
    void Add(const Card& c);

    int Size() const;
    const vector<Card>& Cards() const;

    // Ambil maksimal 5 kartu dari tangan berdasarkan index.
    // Index pakai 0..Size-1.
    // Menghapus kartu yang dimainkan dari tangan, lalu mengembalikan kartu yang dimainkan.
    vector<Card> PlaySelected(const vector<int>& indices);

private:
    vector<Card> cards;

    void ValidatePlay(const vector<int>& indices) const;
};