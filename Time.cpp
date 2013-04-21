#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time {
public:
  string whatTime( int seconds ) {
   	std::vector<int> v;
   	string str = "aaaa";

    int hour = seconds / 3600;
    int minute = seconds / 60 % 60;
    int second = seconds % 60;
    char ret[20];
    sprintf(ret, "%d:%d:%d", hour, minute, second);
    return ret;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int seconds               = 0;
			string expected__         = "0:0:0";

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seconds               = 3661;
			string expected__         = "1:1:1";

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seconds               = 5436;
			string expected__         = "1:30:36";

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seconds               = 86399;
			string expected__         = "23:59:59";

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int seconds               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int seconds               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int seconds               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Time().whatTime(seconds);
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
