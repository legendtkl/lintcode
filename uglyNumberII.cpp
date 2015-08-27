/*  From leetcode
 *	Write a program to find the n-th ugly number
 *	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *	For example, 1,2,3,4,5,6,8,9,10,12 is the sequence of the first 10 ugly numbers
 */

class Solution {
public:
	int nthUglyNuber(int n) {
		vector<int> ugly{1};
		int primer[] = {2,3,5};

		for(int i=1; i<n; i++) {
			int ugly_n = ugly.size();
			vector<int> nums;
			for(int j=0; j<3; j++) {
				for(int k=0; k<ugly_n; k++)
					if(ugly[k]*primer[j]>ugly[ugly_n-1]) {
						nums.push_back(ugly[k]*primer[j]);
						break;
					}
			}
			ugly.push_back(min(nums[0], min(nums[1],nums[2])));
		}
		return ugly[n-1];
	}
}
