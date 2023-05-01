//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        
        
        for ( int i=0; i<n; i++) {
            for ( int j=0 ; j<n-1-i; j++) {
                cout<<" ";
            }
            for ( int j=0; j<i+1; j++) {
                cout<<"* ";
            }
            cout<<endl;
        }
            for ( int i=0; i<n; i++) {
                for ( int j=0; j<i; j++) {
                    cout<<" ";
                }
                
                for ( int j=0; j<n-i; j++) {
                    cout<<"* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends