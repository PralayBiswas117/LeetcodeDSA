class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        string hex = "0123456789abcdef";
        string ans;

        unsigned int n = num;

        while (n > 0) {
            ans += hex[n & 15]; // n & 15 extracts last 4 bits
            n >>= 4;            // remove last 4 bits
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};