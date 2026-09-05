class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to avoid overflow when taking abs(INT_MIN)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient = 0;
        
        while (a >= b) {
            long long temp_b = b;
            long long count = 1;
            
            while (a >= (temp_b << 1)) {
                temp_b <<= 1;
                count <<= 1;
            }
            
            a -= temp_b;
            quotient += count;
        }
        
        return negative ? -quotient : quotient;
    }
};