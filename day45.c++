class Solution {
public:
    // Function to add two binary numbers represented as strings
    string addBinary(string a, string b) {
        // Initialize two pointers to traverse the binary strings from right to left
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        // Loop until both pointers have reached the beginning of their respective strings and there is no carry-over value left
        while(i >= 0 ||   j >= 0  || carry) {
            // Add the current binary digit in string a, if the pointer is still within bounds
            if(i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            
            // Add the current binary digit in string b, if the pointer is still within bounds
            if(j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            
            // Calculate the next binary digit in the result by taking the remainder of the sum divided by 2
            ans += (carry % 2 + '0');
            
            // Calculate the next carry-over value by dividing the sum by 2
            carry = carry / 2;
        }
        
        // Reverse the result and return it as a string
        reverse(ans.begin(), ans.end());
        return ans;
    }
};