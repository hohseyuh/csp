#include "csputils.h"
using namespace std;

// mrv — en kicik dominli deyiwenleri secir
int selectVariableMRV(const CSPGraph& g,
                      const unordered_map<int, vector<int>>& domain,
                      const unordered_map<int, int>& assignment) {
    int chosen = -1;
    size_t minSize = numeric_limits<size_t>::max();

    for (int var : g.variables) {
        if (assignment.count(var)) continue;
        size_t size = domain.at(var).size();
        if (size < minSize) {
            minSize = size;
            chosen = var;
        }
    }
    return chosen;
}

// lcv — rengleri domain kicikliyine gore eliminate edir
vector<int> orderLCV(int var,
                     const CSPGraph& g,
                     const unordered_map<int, vector<int>>& domain) {
    vector<pair<int,int>> impact; // color, penalty

    for (int color : domain.at(var)) {
        int penalty = 0;
        for (int n : g.adj.at(var))
            for (int c : domain.at(n))
                if (c == color) penalty++;
        impact.push_back({color, penalty});
    }

    sort(impact.begin(), impact.end(),
         [](auto& a, auto& b){ return a.second < b.second; });

    vector<int> ordered;
    for (auto& [c, _] : impact)
        ordered.push_back(c);
    return ordered;
}
