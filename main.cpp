#include <iostream>
#include <limits>
#include <conio.h>   // _getch()

enum class MenuChoice {
    Start = 1,
    Quit = 2
};

MenuChoice ShowMainMenu() {
    while (true) {
        std::cout << "\n=== MAIN MENU ===\n";
        std::cout << "1. Start\n";
        std::cout << "2. Quit\n";
        std::cout << "Pilih: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input tidak valid. Masukkan angka 1 atau 2.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == static_cast<int>(MenuChoice::Start)) return MenuChoice::Start;
        if (choice == static_cast<int>(MenuChoice::Quit))  return MenuChoice::Quit;

        std::cout << "Pilihan tidak ada. Masukkan 1 atau 2.\n";
    }
}

void StartGameStub() {
    std::cout << "\nGame Started\n";
    std::cout << "Tekan Esc untuk kembali ke menu.\n";

    while (true) {
        int ch = _getch();
        if (ch == 27) break;  
    }
}

int main() {
    while (true) {
        MenuChoice choice = ShowMainMenu();

        if (choice == MenuChoice::Start) {
            StartGameStub();
        }
        else if (choice == MenuChoice::Quit) {
            std::cout << "\nQuitting...\n";
            break;
        }
    }
    return 0;
}