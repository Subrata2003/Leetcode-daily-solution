class Solution {
    public int findMinArrowShots(int[][] points) {
        int result = 0;
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((a,b) -> a[1]-b[1]);
        for (int []point : points) priorityQueue.add(point);
        if (priorityQueue.isEmpty()) return 0;
        while (!priorityQueue.isEmpty()) {
            int [] prev = priorityQueue.poll();
            while (!priorityQueue.isEmpty() && prev[1]>=priorityQueue.peek()[0] && prev[1]<=priorityQueue.peek()[1]) {
                priorityQueue.poll();
            }
            result++;
        }
        return result;
    }
}
