#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestSubsequence(vector<int>& A){
		int pos=0, n=A.size(), ret=1;

		while(pos<n){
			int i=pos+1;
			while(A[i]>A[i-1)
		}
	}

	void reverseVector(vector<int>& A){
		int left=0, right=A.size()-1;
		while(left<right){
			int tmp = A[left];
			A[left] = A[right];
			A[right] = tmp;
			++left;
			--right;
		}
	}

	int longestIncreasingContinuousSubsequence(vector<int>& A) {
		int incr = longestSubsequence(A);
		reverseVector(A);
		int decr = longestSubsequence(A);
		return max(incr, decr);
	}
};

int main(){
	vector<int> A{99,55,7,29,80,33,19,23,6,35,40,27,44,74,5,17,52,36,67,32,37,42,18,77,66,62,97,79,60,94,30,2,85,22,26,91,3,16,8,0,48,93,39,31,63,13,71,58,69,50,21,70,61,43,12,88,47,45,72,76};
	Solution solve;
	cout << solve.longestIncreasingContinuousSubsequence(B) << endl;
	return 0;
}
