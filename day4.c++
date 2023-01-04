/*You are given a 0-indexed integer array tasks, where tasks[i] represents the
 difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.*/


class Solution 
{
public:
    int dp[100001];
    bool flag = false;
    int minimumRounds(vector<int>& tasks)
    {
        map<int,int>mp;
        for(auto & e:tasks)
            mp[e]++;
        if(!flag)
        {
            dp[0] = INT_MAX/2;dp[1] = INT_MAX/2;
            dp[2] = 1;dp[3] = 1;
            for(int i = 4;i<=100000;i++)
                dp[i] = min(dp[i-2],dp[i-3]) + 1;
            flag = true;
        }
        int ans = 0;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second == 1)
                return -1;
            ans += dp[it->second];
        }
        return ans;
    }
};