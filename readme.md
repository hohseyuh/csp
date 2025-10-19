Task 2: CSP
===
## 1. How to Run
In order to run application use `./csp "filename"` inside the `/csp/`directory where `csp.exe` locates.

## 2. Report
##### csp_small.txt:
~~~
SOLUTION: {4: 1, 3: 3, 2: 2, 1: 1}
~~~
##### csp_tight.txt:
~~~
failure
~~~
##### csp_tight_solvable.txt:
~~~
SOLUTION: {12: 3, 11: 2, 10: 4, 6: 3, 9: 1, 8: 4, 7: 1, 5: 3, 4: 2, 3: 3, 2: 2, 1: 1}
~~~

## 3. File Structure
~~~
cspmain.cpp         -> main file
csp.cpp             -> csp algorithm
graphParser.cpp     -> graph parser function
heuristics.cpp      -> mrv and lcv functions
backtrack.cpp       -> backtracking function
ac3.cpp             -> contains ac3 algorithm
csputils.h          -> shared header for all .cpp files, contains data structures, 
                       declares every function and printSolution
~~~