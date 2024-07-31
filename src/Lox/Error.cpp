#include <iostream>
#include "Error.hpp"
using namespace std;

void ErrorHandle::Error(string message, long int line)
{
    if (line != 0)
    {
        Report(line, "", message);
        exit(65);
    }
    else
    {
        cout << "Error: " << message;
    }
}

void ErrorHandle::Report(long int line, string where, string message)
{
    string mess_age = "[line " + to_string(line) + "] Error" + where + ": " + message;
    cout << mess_age;
}