class Solution {
public:
 
    template<typename T_a3, typename T_vector>
    void bellman_ford(T_a3 &g, T_vector &dist, int src, int mx_edges) {
        dist[src] = 0;
        for (int i = 0; i <= mx_edges; i++) {
            T_vector ndist = dist;
            for (auto x : g) {
                auto [from, to, cost] = x;
                ndist[to] = min(ndist[to], dist[from] + cost);
            }
            dist = ndist;
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we can directly use bellman ford template here (prerequisite: you need to understand bellman ford algo)
        // bellman ford algo is used to find the shortest paths from source node to other nodes in a weighted graph
        vector<array<int, 3>> g;
        // initially cost with a large value
        // cost[i] means the cheapest price from src to city i
        vector<int> cost(n, 1e9);
        // reconstruct a bit - {src, dst, cost}
        for (auto f : flights) g.push_back({f[0], f[1], f[2]});
        bellman_ford(g, cost, src, k);
        // if cost[dst] == 1e9, it means it is unreachable
        // else we can show cost[dst]
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};