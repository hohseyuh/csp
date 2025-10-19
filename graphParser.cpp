#include "csputils.h"
using namespace std;

CSPGraph parseGraph(const string& filename) {
    CSPGraph graph;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        stringstream ss(line);

        if (line.rfind("colours", 0) == 0) {
            int colorCount = stoi(line.substr(line.find('=') + 1));
            graph.k = colorCount;
        } else {
            int a, b;
            char comma;
            ss >> a >> comma >> b;
            graph.adj[a].push_back(b);
            graph.adj[b].push_back(a);
        }
    }

    for (auto& [v, _] : graph.adj)
        graph.variables.push_back(v);
    sort(graph.variables.begin(), graph.variables.end());

    file.close();
    return graph;
}
