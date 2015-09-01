class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> v;

		for(size_t i=0; i!=k; ++i)
			v.push_back(nums[i]);
		make_heap(v.begin(), v.end(), greater<int>());
		for(size_t i=k; i<nums.size(); ++i){
			if(nums[i]<=v[0])
				continue;
			pop_heap(v.begin(), v.end());
			v.pop_back();
			v.push_back(nums[i]);
			push_heap(v.begin(), v.end());
			sort_heap(v.begin(), v.end());
		}

		return v[0];
	}
};
