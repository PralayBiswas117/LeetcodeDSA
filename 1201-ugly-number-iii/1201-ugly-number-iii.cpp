#include <numeric>

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {

        long long A = a;
        long long B = b;
        long long C = c;

        long long ab = std::lcm(A, B);
        long long ac = std::lcm(A, C);
        long long bc = std::lcm(B, C);
        long long abc = std::lcm(ab, C);

        long long low = 1;
        long long high = 2000000000LL;
        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            long long count =
                mid / A +
                mid / B +
                mid / C -
                mid / ab -
                mid / ac -
                mid / bc +
                mid / abc;

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};