// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    //assert(0 < i && i <= j);
    if (j < i) {
        int temp = i;
        i = j;
        j = temp;}
    int max_cycles = 0;
    for (; i <= j; ++i) {
        long long int n = i;
        int cycles = 1;
        while (n > 1) {
            ++cycles;
            if (n % 2) {
                n = 3 * n + 1;}
            else {
                n /= 2;}}
        assert(n == 1);
        if (cycles > max_cycles) {
            max_cycles = cycles;}}
    assert(max_cycles > 0);
    return max_cycles;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
