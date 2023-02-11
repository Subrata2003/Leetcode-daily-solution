class Solution {
      public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        // Two sets one for blu and another for red
        Set<Integer>[][] graph = new HashSet[2][n];
        for (int i = 0; i < n; i++) {
            graph[0][i] = new HashSet<>();
            graph[1][i] = new HashSet<>();
        }
        // red edges in 0 - col
        for (int[] re : red_edges) {
            graph[0][ re[0] ].add(re[1]);
        }
        // blu edges in 1 - col
        for (int[] blu : blue_edges) {
            graph[1][ blu[0] ].add(blu[1]);
        }
        int[][] res = new int[2][n];
        // Zero edge is always accessible to itself - leave it as 0
        for (int i = 1; i < n; i++) {
            res[0][i] = 2 * n;
            res[1][i] = 2 * n;
        }
        // Q entries are vert with a color (up to that point)
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {0, 0}); // either with red
        q.offer(new int[] {0, 1}); // or with blue
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int vert = cur[0];
            int colr = cur[1];
            // No need to keep track of level up to now
            // only need to keep what color - and the length
            // is automatically derived from previous node
            for (int nxt : graph[1 - colr][vert]) {
                if (res[1 - colr][nxt] == 2 * n) {
                    res[1 - colr][nxt] = 1 + res[colr][vert];
                    q.offer(new int[] {nxt, 1 - colr});
                }
            }
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int t = Math.min(res[0][i], res[1][i]);
            ans[i] = (t == 2 * n) ? -1 : t;
        }
        return ans;
    }
}