class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    const int n = vals.size();
    int ans = n;
    UnionFind uf(n);
    vector<vector<int>> graph(n);
    map<int, vector<int>> valToNodes;

    for (int i = 0; i < vals.size(); ++i)
      valToNodes[vals[i]].push_back(i);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      if (vals[v] <= vals[u])
        graph[u].push_back(v);
      if (vals[u] <= vals[v])
        graph[v].push_back(u);
    }

    for (const auto& [val, nodes] : valToNodes) {
      for (const int u : nodes)
        for (const int v : graph[u])
          uf.unionByRank(u, v);
      unordered_map<int, int> rootCount;
      for (const int u : nodes)
        ++rootCount[uf.find(u)];
      // For each group, C(count, 2) := count * (count - 1) / 2
      for (const auto& [_, count] : rootCount)
        ans += count * (count - 1) / 2;
    }

    return ans;
  }
};