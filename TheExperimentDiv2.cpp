#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TheExperimentDiv2 {
public:
  vector <int> determineHumidity( vector <int> intensity, int L, vector <int> leftEnd ) {
  	vector<int> ans;
  	vector<int> flg;
  	int size = leftEnd.size();
  	int memo[size];
  	for (int i=0; i<size ;i++) {
  		memo[i] = 0;
  	}

  	for (int i=0; i<size ;i++) {
  		int left  = leftEnd.at(i);
  		int right = left + L - 1;
  		int tmp=0;
  		for (int j=left; j<=right ;j++) {
  			if (memo[j] != -1) {
  				tmp += intensity[j];
  				memo[j] = -1;
  			}
  		}
  		ans.push_back(tmp);
  	}

  	return ans;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int intensity[]           = {3, 4, 1, 1, 5, 6};
			int L                     = 3;
			int leftEnd[]             = {3, 1, 0};
			int expected__[]          = {12, 5, 3 };

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int intensity[]           = {5, 5};
			int L                     = 2;
			int leftEnd[]             = {0, 0};
			int expected__[]          = {10, 0 };

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int intensity[]           = {92, 11, 1000, 14, 3};
			int L                     = 2;
			int leftEnd[]             = {0, 3};
			int expected__[]          = {103, 17 };

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int intensity[]           = {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13};
			int L                     = 4;
			int leftEnd[]             = {1, 7, 4, 5, 8, 0};
			int expected__[]          = {39, 14, 110, 0, 13, 2 };

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int intensity[]           = ;
			int L                     = ;
			int leftEnd[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int intensity[]           = ;
			int L                     = ;
			int leftEnd[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int intensity[]           = ;
			int L                     = ;
			int leftEnd[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
