#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	bool isPalindrome(string& s) {
		int left=0, right=s.size()-1;

		while(left<right){
			while(!isalnum(s[left]))
				++left;
			while(!isalnum(s[right]))
				--right;
			if(tolower(s[left])==tolower(s[right]) ){
				++left;
				--right;
			}
			else
				return false;
		}
		return true;
	}
};

int main(){
	string s = "race a car";
	Solution solve;
	cout << solve.isPalindrome(s) << endl;
	return 0;
}
