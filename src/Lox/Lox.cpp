#include "Lox.hpp"
#include <iostream>

Lox::Lox(){
    exit = 0;

}

std::string Lox::Run(std::string instruction){
    if(instruction != ""){
        return instruction + "\n>>>";
    }
    else{
        return "\n>>> ";
    }
}

