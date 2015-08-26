#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	struct Node {
		int val, start;
		Node(int _val, int _start): val(_val), start(_start){}
	};
	vector<int> continuousSubarraySumII(vector<int>& A){
		int n = A.size();
		cout << n << endl;
		vector<Node> sum;
		vector<int> sum2;
		sum.push_back(Node(A[0], 0));
		sum2.push_back(A[0]);

		for(int i=1; i!=n; ++i){
			sum2.push_back(sum2[i-1]+A[i]);
			if(sum[i-1].val+A[i]>A[i]){
				sum.push_back(Node(sum[i-1].val+A[i], sum[i-1].start));
			}else{
				sum.push_back(Node(A[i], i));
			}
		}
		
	//	for(int i=0; i<n; i++)
	//		cout << sum[i].val << endl;
			
		int max_val=sum[n-1].val, left=sum[n-1].start, right=0;
		for(int i=0; i<sum[n-1].start; i++){
			if(sum[n-1].val+sum2[i]>max_val){
				max_val = max_val+sum2[i];
				right = i;
			}
		}
		for(int i=0; i<n; i++){
			if(max_val < sum[i].val){
				max_val = sum[i].val;
				left = sum[i].start;
				right = i;
			}
		}
		return vector<int>{left,right};
	}
};

int main(){
	vector<int> A{37,90,40,73,80,12,84,-2,43,82,31,91,-32,-5,23,48,37,-32,42,42,12,59,46,99,30,3,-39,31,48,26,-1,-22,49,20,-1,72,92,70,-26,8,29,11,-39,92,25,80,78,5,-46,-28,35,-15,-26,9,1,-23,55,94,47,6,57,67,93,-12,87,47,-12,-29,-7,-48,2,11,46,1,-50,59,39,-38,28,97,60,10,29,75,71,57,15,66,1,8,-22,23,19,35,48,50,95,59,-38,79,11,-6,67,66,-46,70,57,-3,41,72,94,-13,56,33,74,-46,22,61,70,-47,9,100,41,-25,62,82,60,67,36,73,8,50,69,52,16,14,86,-41,88,2,-25,16,-23,89,12,53,-46,-20,-5,8,-11,76,-27,60,-19,-3,53,11,10,-5,55,47,-49,-21,-10,7,-24,6,20,6,89,77,-1,-45,85,96,33,66,5,13,72,-6,32,50,87,-9,-43,29,84,96,70,86,76,42,48,3,75,-26,40,25,-9,-15,-48,38,32,78,61,43,-29,57,1,79,23,61,36,15,8,45,88,-8,-12,40,64,21,-28,-1,8,90,-44,75,-32,-20,93,98,97,29,75,26,-21,6,-34,91,49,79,-10,65,11,44,66,76,77,87,-27,-4,96,43,-12,29,58,25,35,-10,84,69,83,82,98,7,78,93,51,21,41,54,-48,-43,17,-48,-40,-20,4,72,-21,-8,-7,8,11,78,77,37,44,95,-17,52,71,3,-14,-6,29,-37,25,63,24,13,62,30,81,64,15,59,56,33,86,-4,96,-35,17,58,97,-38,36,-16,10,60,44,45,46,-37};
	Solution solve;
	vector<int> ret = solve.continuousSubarraySumII(A);
	cout << ret[0] << ret [1] << endl;
}
