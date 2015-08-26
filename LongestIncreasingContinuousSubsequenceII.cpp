#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int DFS(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y){
        int m=A.size(), n=A[0].size();
        if(B[x][y]!=-1)
            return B[x][y];
        int direct[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        int ret = 1;
        for(int i=0; i<4; i++){
            int xx=x+direct[i][0], yy=y+direct[i][1];
            if(xx<0 || xx>=m || yy<0 || yy>=n)
                continue;
            if(A[xx][yy] >= A[x][y])
                continue;
            ret = max(ret, DFS(A,B,xx,yy)+1);
        }
        B[x][y] = ret;

        return ret;
    }
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        int m=A.size();
        if(m==0)    return 0;
        int n=A[0].size();
        
        vector<vector<int>> B(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                DFS(A,B,i,j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
				cout << B[i][j] << '\t';
			cout << endl;
        }
		
        int ret=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                ret = max(ret, B[i][j]);
        }
        return ret;
    }
};

int main(){
	vector<vector<int>> A{{1,2,3,4,5,6},{14,15,16,17,18,8},{12,13,11,10,9,7}};
	Solution solve;
	cout << solve.longestIncreasingContinuousSubsequenceII(A) << endl;
	return 0;
}
