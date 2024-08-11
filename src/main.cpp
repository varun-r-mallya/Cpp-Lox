#include "Lox/Lox.hpp"

int main(int argc, char *argv[]) {
    Lox L;
    if (argc > 2) {
        std::cout << "Usage: cpp-lox [script]\n";
        exit(-1);
    } else if (argc == 1) {
        L.RunLine();
    } else if (argc == 2) {
        if (!L.RunFile(argv[1])) {
            exit(-1);
        }
    }
}