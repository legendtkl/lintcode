#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	string simplifyPath(string& path) {
		stack<string> directory;
		int pos=0, n=path.size();

		while(pos<n){
			while(pos<n && path[pos]=='/')
				pos ++;
			if(pos==n)	break;
			int i=pos;
			for(; i<n && path[i]!='/'; ++i)
				;
			if(i==n)	break;
			cout << "pos: " << pos << ", i: " << i << endl;
			string dir = path.substr(pos, i-pos);
			if(dir==".." && !directory.empty())
				directory.pop();
			else if(dir!=".")
				directory.push(dir);
			pos = i;
		}
		
		vector<string> tmp;
		while(!directory.empty()){
			tmp.push_back(directory.top());
			directory.pop();
		}
		string ret;
		/*
		for(int i=tmp.size()-1; i>=0; --i)
			ret += "/" + tmp[i];
		if(ret=="")
			ret = "/";
		*/
		return ret;
	}
};

int main(){
	string s = "/home/";
	Solution solve;
	cout << solve.simplifyPath(s) << endl;
	return 0;
}
