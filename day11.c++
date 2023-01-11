class Solution {
public:

    bool dfs(int node, vector<bool>& hasApple, vector<int> adj[], int &time, vector<bool> &vis){
        if(adj[node].empty()) return (hasApple[node] == true);

        vis[node]=1;

        bool curr = false;

        for(auto x : adj[node]){
            time += 2;
            bool check = false;
            if(vis[x] == false){
                check = dfs(x,hasApple,adj,time,vis);
            }
            if(!check) time -= 2;
            else curr=true;

        }

        return (curr || (hasApple[node] == true));
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n,false);
        int time=0;
        dfs(0,hasApple,adj,time,vis);
        return time;
    }
};