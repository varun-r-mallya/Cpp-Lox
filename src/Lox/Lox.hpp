#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "Error.hpp"
using namespace std;

class Lox
{
private:
public:
    bool exit;
    Lox();
    void RunLine();
    bool RunFile(string);
    string Run(string, long int);
    ErrorHandle Report;
};