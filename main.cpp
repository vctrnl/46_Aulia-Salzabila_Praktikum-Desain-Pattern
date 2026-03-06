#include <iostream>
#include "RunSession.h"

using namespace std;

int main() {
    cout << "Balatro-like prototype\n";
    RunSession run;          // seed random, jadi kartu yang keluar beda tiap program run
    run.Start();
    cout << "Selesai\n";
    return 0;
}