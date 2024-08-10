#include "Lox.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Scanner.hpp"
using namespace std;

Lox::Lox()
{
    exit = 0;
}

void Lox::RunLine()
{
    std::cout << "CPP-LOX version 0.0.1"; // UPDATE TO 0.1 when I am happy with atleast the first implementation.
    while (!exit)
    {
        std::string instruction;
        std::cout << "\n>>> ";
        getline(cin, instruction, '\n');
        std::cout << Run(instruction);
    }
}

bool Lox::RunFile(string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContents = buffer.str();

    // Close the file
    file.close();

    // TODO: remove these testing lines
    Scanner S(fileContents);
    auto tokens = S.scanTokens();
    cout << "number of tokens: " << tokens.size() << "\n";
    for (auto token : tokens)
    {
        cout << "these are the token attributes: ";
        cout << token.lexeme << " lexeme " << token.line << " line " << token.literal << " literal " << token.type << " type " << std::endl;
    }

    // TODO: remove the comments on this
    //  if(hadError){
    //  logic for not running the program if there are errors in the scanner
    //  }
    return 0;
}

string Lox::Run(string instruction)
{
    // TODO: remove these testing lines
    Scanner S(instruction);
    auto it = S.scanTokens();
    cout << "SIZE OF THE TOKENS COUNTED: " << it.size() << "\n";
    for (auto p : it)
    {
        std::cout << p.lexeme << " " << p.line << " " << p.literal << " " << p.type << "\n";
    }
    return instruction;
}

void Lox::error(string message, long int line)
{
    hadError = true;
    if (line != 0)
    {
        Report(line, "", message);
    }
    else
    {
        cout << "Error: " << message;
    }
}

void Lox::Report(long int line, string where, string message)
{
    string mess_age = "[line " + to_string(line) + "] Error" + where + ": " + message;
    cout << mess_age;
}