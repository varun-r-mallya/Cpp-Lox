#pragma once

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Lox {
private:
public:
    bool exit;

    Lox();

    void RunLine() const;

    static bool RunFile(const string &);

    static string Run(string);

    static void Report(long int line, const string &where, const string &message);

    void error(const string &message, long int line = 0);

    bool hadError = false;
};