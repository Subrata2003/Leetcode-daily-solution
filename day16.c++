class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        
        //smaller, no intersection
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            ++i;
        }
        
        //having intersection
        int start = newInterval[0], end = newInterval[1];
        while(i < n && intervals[i][0] <= end){
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
            ++i;
        }
        
        ans.push_back({start, end});
        
        while(i < n){
            ans.push_back(intervals[i]);
            ++i;
        }
        
        return ans;
    }
};