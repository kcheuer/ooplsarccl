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
#include <unordered_map>

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

static unordered_map<long long int, int> cycles_cache;

int collatz_eval_helper(long long int n) {
    assert(n > 0);
    if (cycles_cache.find(n) == cycles_cache.end()) {
        cycles_cache[n] = 1 + collatz_eval_helper((n%2) ? (3*n+1) : (n/2));}
    return cycles_cache[n];}

int collatz_eval (int i, int j) {
    //assert(0 < i && i <= j);
    if (j < i) {
        int temp = i;
        i = j;
        j = temp;}
    cycles_cache[1] = 1;
    int max_cycles = 0;
    for (; i <= j; ++i) {
        int cycles = collatz_eval_helper(i);
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
