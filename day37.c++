class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int first = 0, second = n, max = 1001;
        for(int i=0;i<2*n;i++)
        {
            if(i%2==0)
            nums[i]=(nums[first++]%max)*max + nums[i];
            else
            nums[i]=(nums[second++]%max)*max + nums[i];
        }
        for(int i=0;i<2*n;i++)
        nums[i]/=max;
        return nums;
    }
};