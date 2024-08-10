#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Lox
{
private:
public:
    bool exit;
    Lox();
    void RunLine();
    bool RunFile(string);
    string Run(string);
    void Report(long int line, string where, string message);
    void error(string message, long int line = 0);
    bool hadError = false;
};