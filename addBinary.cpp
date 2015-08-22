#include <iostream>

using namespace std;

class Solution{
public:
	string addBinary(string& a, string& b) {
		int na=a.size()-1, nb=b.size()-1, flag=1;
		string ret;

		while(na>=0 || nb>=0 || flag){
			int local = flag;
			if(na>=0){
				local += a[na]-'0';
				--na;
			}
			if(nb>=0){
				local += b[nb]-'0';
				--nb;
			}
			flag = local/2;
			local = local%2;

			ret = string(1, local+'0') + ret;
		}

		return ret;
	}
};
