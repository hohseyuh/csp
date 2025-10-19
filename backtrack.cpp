#include "csputils.h"
using namespace std;

bool backtrack(unordered_map<int, int>& assignment,
               unordered_map<int, vector<int>>& domain,
               const CSPGraph& g) {
    if (assignment.size() == g.variables.size())
        return true;

    int var = selectVariableMRV(g, domain, assignment);
    if (var == -1) return false;

    vector<int> values = orderLCV(var, g, domain);

    for (int color : values) {
        if (isConsistent(var, color, g, assignment)) {
            assignment[var] = color;
            auto backup = domain;
            domain[var] = {color};

            if (ac3(domain, g)) if (backtrack(assignment, domain, g)) return true;

            domain = backup;
            assignment.erase(var);
        }
    }
    return false;
}
