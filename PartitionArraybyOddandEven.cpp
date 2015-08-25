class Solution {
public:
	void partitionArray(vector<int> &nums){
		int left=0,right=nums.size()-1;
		while(left<right){
			while(left<right && nums[left]%2)
				left ++;
			while(right>left && nums[right]%2==0)
				right--;
			int tmp = nums[left];
			nums[left] = nums[right];
			nums[right] = tmp;
			left ++;
			right --;
		}
	}
};
