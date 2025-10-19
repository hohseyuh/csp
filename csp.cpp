#include "csputils.h"
using namespace std;

CSPResult solveCSP(const CSPGraph& g) {
    unordered_map<int, vector<int>> domain;
    unordered_map<int, int> assignment;

    // initialize domains
    for (int var : g.variables)
        for (int c = 1; c <= g.k; c++)
            domain[var].push_back(c);

    // initial consistency
    if (!ac3(domain, g)) return {false, {}};

    CSPResult result;
    result.solved = backtrack(assignment, domain, g);
    result.assignment = assignment;
    return result;
}
