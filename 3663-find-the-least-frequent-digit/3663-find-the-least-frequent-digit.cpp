class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int freq[10] = {0};

        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        int minFreq = INT_MAX;
        int result = 9;

        for (int i = 0; i < 10; i++) {
            if (freq[i] > 0 && (freq[i] < minFreq || (freq[i] == minFreq && i < result))) {
                minFreq = freq[i];
                result = i;
            }
        }

        return result;
    }
};