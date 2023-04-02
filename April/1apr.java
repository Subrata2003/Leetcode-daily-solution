class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length-1;
int start=0;
int end=n,mid;

    while(start <= end)
    {
        mid=(start + end)/2;
        if(nums[mid] == target) return mid;
        else
        {
            if(target>nums[mid])  start=mid+1;
            else end = mid -1;
        }
    }
    return -1;
    
    }
}
