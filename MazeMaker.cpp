#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

class MazeMaker {
public:
  int longestPath( vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol ) {
    int max = 0;
    int width  = maze[0].size();
    int height = maze.size();
    int board[height+1][width+1];

    for (int i=0; i<height ;i++) {
    	for (int j=0; j<width ;j++) {
    		board[i][j] = -1;
    	}
    }
    board[startRow][startCol] = 0;

    queue<int> queueX;
    queue<int> queueY;
    queueX.push(startCol);
    queueY.push(startRow);

    while (!queueX.empty()) {
    	int x = queueX.front();
    	int y = queueY.front();
    	queueX.pop();
    	queueY.pop();

      int rowSize = moveRow.size();
    	for (int i=0; i<rowSize ;i++) {
    		int nextX = x + moveCol[i];
    		int nextY = y + moveRow[i];
    		if (nextX >=0 && nextX < width
    				&& nextY >=0 && nextY < height
    				&& board[nextY][nextX] == -1
    				&& maze[nextY].substr(nextX, 1) == ".") {
    			board[nextY][nextX] = board[y][x] + 1;
    			queueX.push(nextX);
    			queueY.push(nextY);
    		}
    	}
    }

    for (int i=0; i<height ;i++) {
      for (int j=0; j<width ;j++) {
        if (maze[i].substr(j, 1) == "." && board[i][j] == -1) {
          return -1;
        }
        max = std::max(max, board[i][j]);
      }
    }

  	return max;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1,0,-1,0};
			int moveCol[]             = {0,1,0,-1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0, 1, 1, -1, -1};
			int moveCol[]             = {0, 1, 0, -1, 1, -1, 1, -1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string maze[]             = {"X.X",
 "...",
 "XXX",
 "X.X"};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0};
			int moveCol[]             = {0, 1, 0, -1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string maze[]             = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
			int startRow              = 5;
			int startCol              = 0;
			int moveRow[]             = {1, 0, -1, 0,-2, 1};
			int moveCol[]             = {0, -1, 0, 1, 3, 0};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string maze[]             = {"......."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {1, 0, 1, 0, 1, 0};
			int moveCol[]             = {0, 1, 0, 1, 0, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string maze[]             = {"..X.X.X.X.X.X."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {2,0,-2,0};
			int moveCol[]             = {0,2,0,-2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
