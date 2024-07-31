#include "Lox.hpp"
#include <iostream>
#include <cstdlib>
#include "Error.hpp"
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
        cout << "\n>>> ";
        getline(cin, instruction, '\n');
        std::cout << Run(instruction, -1);
    }
}

bool Lox::RunFile(string filename)
{
    string line;
    ifstream script(filename);
    if (script.is_open())
    {
        long int p = 0;
        while (getline(script, line))
        {
            p++;
            cout << Run(line, p) << "\n";
        }
        script.close();
        return 1;
    }

    else
        cout << "Unable to open file\n";
    return 0;
}

string Lox::Run(string instruction, long int line)
{
    // this part of the function just selects if the lines are interactive or are being read from a file
    if (line == -1)
    {
        // this is being read interactively

        // TODO: this is a tester function that activates the error on purpose
        if (instruction == "makeerror();")
        {
            Report.Error("Error made successfully");
            return "";
        }
        return instruction;
    }

    // TODO: this is a tester function that activates the error on purpose
    if (instruction == "makeerror();")
    {
        Report.Error("Error made successfully", line);
        exit = 1;
        return "";
    }
    return instruction;
}
