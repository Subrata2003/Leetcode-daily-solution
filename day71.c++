//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
         int mxcount = 0;
        int row_num = 0;
        for(int i = 0; i<N; i++){
             vector<int>::iterator upper;
             upper = upper_bound(mat[i].begin(), mat[i].end(), 0) ;
             int temp =  N - (upper - mat[i].begin());
             if(temp > mxcount){
                 mxcount = temp;
                 row_num = i;
             }
        }
       return {row_num , mxcount};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends