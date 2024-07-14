#include "Lox/Lox.hpp"

int main(int argc, char *argv[]) {
    Lox L;
    if(argc > 2){
        std::cout<<"Usage: cpp-lox [script]\n";
        exit(-1);
    }
    else if(argc == 1){
        std::cout<<"CPP-LOX version 0.0.1\n>>> "; //UPDATE TO 0.1 when I am happy with atleast the first implementation. 
        while(!L.exit){
            std::string instruction;
            std::cin>>instruction;
            std::cout<<L.Run(instruction);

        }
    }
    else if(argc == 2){
        std::cout<<argv[1];
    }
}