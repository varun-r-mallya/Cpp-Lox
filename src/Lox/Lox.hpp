#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Lox {
    private:

    public:
        bool exit;
        Lox();
        void RunLine();
        bool RunFile(string);
        string Run(string);

};