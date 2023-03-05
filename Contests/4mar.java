class Solution {
    
        public int splitNum(int num) {
        char[] ca = Integer.toString(num).toCharArray();
        Arrays.sort(ca);
        int a = 0, b = 0;
        for (int i = 0; i < ca.length; ++i) {
            int digit = ca[i] - '0';
            if (i % 2 == 0) {
                a *= 10;
                a += digit;
            }else {
                b *= 10;
                b += digit;
            }
        }
        return a + b;
    }
    }
