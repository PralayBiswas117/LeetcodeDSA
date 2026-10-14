class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        long long place = 1;

        while (n) {
            int digit = n % 10;

            if (digit) {
                ans += digit * place;
                place *= 10;
            }

            n /= 10;
        }

        return ans;
    }
};