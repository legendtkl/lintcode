class Solution {
	public:
		int bitSwapRequired(int a, int b) {
			int x=a^b, counter=0;

			while(x){
				counter++;
				x = x&(x-1);
			}

			return counter;
		}
};
