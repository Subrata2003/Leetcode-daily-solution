class Solution {
public:
    char dfs(char c, vector<char>& unionGraph) {
        if(unionGraph[c] != '\0') return dfs(unionGraph[c], unionGraph);
        return c;
    }
    void merge(char big, char small, vector<char>& unionGraph) {
        if(big=='\0' || small == '\0') return;
        if(unionGraph[big] > small) {
            // cout<<unionGraph[big]<<" "<<small<<endl;
            merge(unionGraph[big], small, unionGraph);
        } else if(unionGraph[big] < small) {
            char temp = unionGraph[small];
            char temp1 = unionGraph[big];
            unionGraph[big] = small;
            unionGraph[small] = temp1;
            merge(small, temp, unionGraph);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> unionGraph(200, '\0');
        for(int i = 0; i < s1.size(); i ++) {
            char big = max(s1[i], s2[i]);
            char small = min(s1[i], s2[i]);
            if(big != small) merge(big, small, unionGraph);
        }
        string res = "";
        for(auto &ch: baseStr) {
            res += dfs(ch, unionGraph);
        }
        return res;
    }
};