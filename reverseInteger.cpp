#include <iostream>

using namespace std;

class Solution{
public:
	int reverseInteger(int n){
		long ret = 0;
		while(n) {
			ret = ret*10 + n%10;
			n /= 10;
		}
		if(ret > INT_MAX || ret<INT_MIN)
			return 0;
		return ret;
	}
};

int main(){
	Solution solve;
	cout << solve.reverseInteger(-321) << endl;
	return 0;
}
