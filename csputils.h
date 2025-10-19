#pragma once
#include <bits/stdc++.h>

using namespace std;

// Data Struktulari

struct CSPGraph {
    unordered_map<int, vector<int>> adj;
    vector<int> variables;
    int k = 0;
};

struct CSPResult {
    bool solved = false;
    unordered_map<int, int> assignment;
};

// Funksiyalar

inline void printSolution(const CSPResult& result) {
    if (!result.solved) {
        cout << "failure\n";
        return;
    }
    cout << "SOLUTION: {";
    bool first = true;
    for (auto& [v, c] : result.assignment) {
        if (!first) cout << ", ";
        cout << v << ": " << c;
        first = false;
    }
    cout << "}\n";
}

inline bool isConsistent(int var, int color,
                         const CSPGraph& g,
                         const unordered_map<int, int>& assignment) {
    for (int n : g.adj.at(var)) {
        auto it = assignment.find(n);
        if (it != assignment.end() && it->second == color)
            return false;
    }
    return true;
}

// Declarations

// graph_parser.cpp
CSPGraph parseGraph(const string& filename);

// ac3.cpp
bool revise(int X, int Y, unordered_map<int, vector<int>>& domain);
bool ac3(unordered_map<int, vector<int>>& domain, const CSPGraph& g);

// heuristics.cpp
int selectVariableMRV(const CSPGraph& g,
                      const unordered_map<int, vector<int>>& domain,
                      const unordered_map<int, int>& assignment);

vector<int> orderLCV(int var,
                     const CSPGraph& g,
                     const unordered_map<int, vector<int>>& domain);

// backtrack.cpp
bool backtrack(unordered_map<int, int>& assignment,
               unordered_map<int, vector<int>>& domain,
               const CSPGraph& g);

// csp.cpp
CSPResult solveCSP(const CSPGraph& g);
