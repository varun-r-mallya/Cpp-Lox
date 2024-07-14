#include "Lox.hpp"
#include <iostream>
using namespace std;

Lox::Lox(){
    exit = 0;

}

void Lox::RunLine(){
    std::cout<<"CPP-LOX version 0.0.1"; //UPDATE TO 0.1 when I am happy with atleast the first implementation. 
    while(!exit){
        std::string instruction;
        cout<<"\n>>> ";
        std::cin>>instruction;
        std::cout<<Run(instruction);
    }
}

bool Lox::RunFile(string filename){
    string line;
    ifstream script (filename);
    if (script.is_open())
    {
      while ( getline (script,line) )
      {
        cout<<Run(line)<<"\n";
      }
      script.close();
      return 1;
    }

    else cout << "Unable to open file\n"; 
    return 0;
}

string Lox::Run(string instruction){
    return instruction;
}

