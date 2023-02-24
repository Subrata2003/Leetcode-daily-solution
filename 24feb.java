class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
        int minValue=Integer.MAX_VALUE;
        for(int x:nums){
            if((x&1)==1)
                x<<=1;
            pq.add(x);
            minValue=Math.min(minValue,x);
        }
        int minDeviation=Integer.MAX_VALUE;
        while(!pq.isEmpty()){
            int curr=pq.poll();
            minDeviation=Math.min(minDeviation,curr-minValue);
            if((curr&1)==1)
                break;
            curr>>=1;
            minValue=Math.min(minValue,curr);
            pq.add(curr);
        }
        return minDeviation;
    }
}
