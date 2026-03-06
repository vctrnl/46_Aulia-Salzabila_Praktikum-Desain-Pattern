#include <iostream>
#include "RunSession.h"

using namespace std;

int main() {
    cout << "Balatro-like prototype\n";
    RunSession run(12345);
    run.Start();
    cout << "Selesai\n";
    return 0;
}