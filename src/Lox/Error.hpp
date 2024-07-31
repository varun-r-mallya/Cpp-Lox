#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ErrorHandle {
    public:
        void Report(long int line, string where, string message);
        void Error(string message, long int line = 0);

};