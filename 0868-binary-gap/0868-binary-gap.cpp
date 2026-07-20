class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int index = 0;
        int ans = 0;

        while (n > 0) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, index - last);
                }
                last = index;
            }

            n >>= 1;
            index++;
        }

        return ans;
    }
};