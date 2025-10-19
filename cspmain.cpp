#include "csputils.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./csp <filename>\n";
        return 1;
    }

    string filename = argv[1];
    CSPGraph graph = parseGraph(filename);
    CSPResult result = solveCSP(graph);

    printSolution(result);
    return 0;
}
