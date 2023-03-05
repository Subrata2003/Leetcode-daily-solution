 public int countWays(int[][] ranges) {
        int res = 1, last = -1, mod = (int)1e9 + 7;
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        for (int[] r: ranges) {   
            if (last < r[0])
                res = res * 2 % mod;
            last = Math.max(last, r[1]);
        }
        return res;
    }
