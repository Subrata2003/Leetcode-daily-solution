class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adjList, string& labels, int parent, int cur, vector<int>& ans){
        vector<int> counter(26, 0);
        char c = labels[cur]-'a';
        counter[c] = 1;
        
        for(int nei : adjList[cur]){
            if(nei != parent){
                vector<int> subcounter = dfs(adjList, labels, cur, nei, ans);
                for(int i = 0; i < counter.size(); ++i){
                    counter[i] += subcounter[i];
                }
            }
        }
        //since we are using dfs, now counter's coverage is the subtree rooted at cur
        ans[cur] = counter[c];
        
        return counter;
    };
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjList(n);
        vector<vector<int>> counter(n, vector<int>(26, -1));
        
        //bi-directional
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n, 0);
        int parent = -1;
        
        dfs(adjList, labels, -1, 0, ans);
        
        return ans;
    }
};;