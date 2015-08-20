#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minimumSize(vector<int> &nums, int s){
		if(s==0)	return 0;
		if(nums.size()==0)	return -1;

		int sum=0, len=INT_MAX, left=0;
		for(int i=0; i!=nums.size(); ++i){
			sum += nums[i];
			if(sum < s)
				continue;
			while(sum >= s){
				sum -= nums[left];
				++left;
			}
			len = min(len, i-left+2);
		}
		return len==INT_MAX ? -1 : len;
	}
}

