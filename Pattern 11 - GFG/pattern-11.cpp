//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int start=1;
        for (int i=0; i<n; i++) {
            if ( i%2 == 0) start = 1;
            else start = 0 ;
            
            for ( int j=0; j<i+1; j++) {
                cout<<start<<" ";
                start=1-start;
            }
            cout<<endl;
        }
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends