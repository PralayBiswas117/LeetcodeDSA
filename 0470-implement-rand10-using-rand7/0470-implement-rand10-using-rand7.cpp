class Solution {
    long long cache = 0;
    long long upper = 1;
    
public:
    int rand10() {
        while (true) {
            // Accumulate randomness until we have at least 10 states
            while (upper < 10) {
                cache = cache * 7 + (rand7() - 1);
                upper *= 7;
            }
            
            // Check if we can cleanly extract
            long long maxUsable = (upper / 10) * 10;
            
            if (cache < maxUsable) {
                // Safe to extract
                int result = cache % 10 + 1;
                cache /= 10;
                upper /= 10;
                return result;
            }
            
            // Cannot extract cleanly - keep remainder and retry
            cache -= maxUsable;
            upper -= maxUsable;
        }
    }
};