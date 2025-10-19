#include "csputils.h"
using namespace std;

bool revise(int X, int Y, unordered_map<int, vector<int>>& domain) {
    bool revised = false;
    vector<int> newDomain;

    for (int x : domain[X]) {
        bool supported = false;
        for (int y : domain[Y]) {
            if (x != y) {
                supported = true;
                break;
            }
        }
        if (supported) newDomain.push_back(x);
        else revised = true;
    }

    if (revised) domain[X] = newDomain;
    return revised;
}

bool ac3(unordered_map<int, vector<int>>& domain, const CSPGraph& g) {
    queue<pair<int, int>> q;
    for (auto& [X, neighbors] : g.adj)
        for (int Y : neighbors)
            q.push({X, Y});

    while (!q.empty()) {
        auto [X, Y] = q.front();
        q.pop();

        if (revise(X, Y, domain)) {
            if (domain[X].empty())
                return false;
            for (int Z : g.adj.at(X))
                if (Z != Y) q.push({Z, X});
        }
    }
    return true;
}
