#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    const long long MAX_VAL = 1000000000LL; // Cap to prevent overflow

    long long nCk(int n, int k) {
        long long res = 1;
        for (int i = 1; i <= std::min(k, n - k); ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_VAL) return MAX_VAL;
        }
        return res;
    }

    long long countArrangements(const std::vector<int>& count) {
        int total = 0;
        for (int c : count) total += c;
        
        long long res = 1;
        for (int freq : count) {
            if (freq == 0) continue;
            res *= nCk(total, freq);
            if (res >= MAX_VAL) return MAX_VAL;
            total -= freq;
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, long long k) {
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        std::vector<int> halfCount(26, 0);
        std::string midLetter = "";
        for (int i = 0; i < 26; ++i) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2 == 1) {
                midLetter = std::string(1, 'a' + i);
            }
        }

        if (countArrangements(halfCount) < k) {
            return "";
        }

        std::string leftHalf = "";
        int halfLen = s.length() / 2;

        for (int step = 0; step < halfLen; ++step) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;
                
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                
                if (arrangements >= k) {
                    leftHalf += ('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        std::string rightHalf = leftHalf;
        std::reverse(rightHalf.begin(), rightHalf.end());
        
        return leftHalf + midLetter + rightHalf;
    }
};