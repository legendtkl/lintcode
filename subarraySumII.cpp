#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	struct sum {
		int val, ending;
		sum(int x, int y):val(x),ending(y){}
	};

	static bool cmp(sum a, sum b){
		return a.val<b.val;
	}
	int subarraySumII(vector<int>& A, int start, int end) {
		vector<sum> sum_array{sum(0,-1)};
		int pos=0, n=A.size(), local=0;
		while(pos<n) {
			local += A[pos++];
			sum_array.push_back(sum(local, pos));
		}
		sort(sum_array.begin(), sum_array.end(), cmp);
		/*
		for(int i=0; i!=sum_array.size(); ++i)
			cout << "val: " << sum_array[i].val << ", ending: " << sum_array[i].ending << endl;
		*/
		int ret=0;
		pos=0;

		while(pos<n+1){
			for(int i=pos+1; i<n+1 && sum_array[i].val-sum_array[pos].val<=end; ++i){
				if(sum_array[i].val-sum_array[pos].val>=start && sum_array[i].ending>sum_array[pos].ending){
					ret ++;
	//				cout << sum_array[pos].ending << '\t' << sum_array[i].ending << endl;
				}
			}
			pos ++;
		}
		return ret;
	}
};

int main(){
	vector<int> A{1,2,3,4};
	Solution solve;
	int ret = solve.subarraySumII(A, 1, 3);
	cout << ret << endl;
	return 0;
}
