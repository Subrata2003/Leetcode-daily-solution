class Solution {
public:

   bool ispalindrome(string s,int start,int last){
       while(start<=last){
           if(s[start++]!=s[last--]){
               return false;
           }
          
       }
       return true;
   }

   void solve(vector<vector<string>> &ans,string s,vector<string> &path,int idx,int n){

     if(idx==n){
         ans.push_back(path);
         return;
     }

     for(int i=idx;i<n;i++){
         if(ispalindrome(s,idx,i)){
             path.push_back(s.substr(idx,i-idx+1));
            solve(ans,s,path,i+1,n);
            path.pop_back();
         }
     }
   }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        solve(ans,s,path,0,n);
        return ans;
    }
};