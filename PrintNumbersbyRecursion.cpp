#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int tag;
	void recursion(vector<int>& ret, int recur_time, int n, int num){
		cout << tag << '\t' << recur_time << endl;
		if(tag>=num)
			return;
		ret.push_back(tag++);
		recur_time ++;

		if(recur_time>=n){
			recur_time--;
			return;
		}else{
			recur_time++;
			recursion(ret, recur_time, n, num);
		}
	}
	vector<int> numbersByRecursion(int n){
		tag=1;
		int num=1;
		for(int i=0; i<n; i++)
			num *= 10;
		vector<int> ret;
		while(tag<num){
			recursion(ret, 0, n, num);
			cout << tag << endl;
		}
		
		return ret;
	}
};

int main(){
	Solution solve;
	vector<int> ret = solve.numbersByRecursion(6);
	for(size_t i=0; i!=ret.size(); ++i)
		cout << ret[i] << endl;
	return 0;
}
