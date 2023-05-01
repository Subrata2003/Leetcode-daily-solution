//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for ( int i=0; i<n; i++) {
            for ( int j=0; j<n-i-1;j++){
                cout<<" ";
            }
            
        char ch='A';
        int breakpoint = (2*i+1)/2;
        
        for ( int j=1; j<=2*i+1; j++){
            cout<<ch;
            if ( j<= breakpoint) ch++;
            else ch--;
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