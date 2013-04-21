#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

string int2str(int a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

class PrefixCode {
public:
   string isOne(vector <string> words) {
	   for (int i=0; i<words.size();++i) {
		   for (int j=0; j<words.size(); ++j) {
			   if (i!=j && words[i] == words[j].substr(0,(words[i].length()))) {
                   printf("hooo");
				   return "No, " + int2str(i);
			   }
		   }
	   }
	   return "Yes";
  }
  void dummy() {
      printf("foo");
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
