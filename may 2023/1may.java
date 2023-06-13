class Solution {
    public static double average(int[] salary) {
        double min = Double.MAX_VALUE, max = Double.MIN_VALUE, avg = 0.0, sum = 0.0;
        for (int i = 0; i < salary.length; i++) {
            min = Math.min(salary[i], min);
            max = Math.max(salary[i], max);
            sum += salary[i];
        }

        avg = sum - min - max;
        return avg / (salary.length - 2);
    }
}
