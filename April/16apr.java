class Solution {
    public int numWays(String[] words, String target) {
        int mod = 1000000007;
        int n = words[0].length();
        int[][] freq = new int[n][26]; // freq[i][j] = frequency of j+'a' in the ith column of the matrix
        
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < n; j++) {
                freq[j][words[i].charAt(j) - 'a']++;
            }
        }
        
        int[][] dp = new int[n+1][target.length()+1]; // dp[i][j] = number of ways to form the prefix of target with length j using the first i columns of the matrix
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target.length(); j++) {
                int charCount = freq[i-1][target.charAt(j-1) - 'a'];
                dp[i][j] = (dp[i-1][j] + (int)((long)charCount * dp[i-1][j-1] % mod)) % mod;
            }
        }
        
        return dp[n][target.length()];
    }
}
