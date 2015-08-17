#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string countAndSay(string s, int n){
		if(n==1)
			return s;
		int pos=0, s_size=s.size();
		stringstream ret;
		while(pos<s_size ){
			int i=pos;
			for(; i<s_size && s[i]==s[pos]; i++)
				;
			ret << i-pos << s[pos];
			pos = i;
		}

		return countAndSay(ret.str(), n-1);
	}
	string countAndSay(int n) {
		return countAndSay("1", n);
	}
};

int main(){
	Solution solve;
	cout << solve.countAndSay(1) << endl;
	cout << solve.countAndSay(2) << endl;
	cout << solve.countAndSay(3) << endl;
	cout << solve.countAndSay(4) << endl;
	cout << solve.countAndSay(5) << endl;
	cout << solve.countAndSay(6) << endl;
	return 0;
}
