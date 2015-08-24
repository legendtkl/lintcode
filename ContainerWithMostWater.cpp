#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height){
		int area=0, left=0, right=height.size()-1;
		
		while(left<right){
			area = max(area, (right-left)*min(height[left],height[right]));
			if(height[left]<height[right]){
				int i=left+1;
				for(; i<=right && height[i]<=height[left]; i++)
					;
				left = i;
			}else{
				int i=right-1;
				for(; i>=left && height[i]<=height[right]; i--)
					;
				right = i;
			}
		}
		return area;
	}
};

int main(){
	int array[] = {1,3,2};
	vector<int> A(array, array+3);
	Solution solve;
	std::cout << solve.maxArea(A) << std::endl;
	return 0;
}
