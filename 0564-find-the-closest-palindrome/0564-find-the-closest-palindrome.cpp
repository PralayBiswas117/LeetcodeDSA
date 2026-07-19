class Solution {
public:
    string nearestPalindromic(string n) {
        long long original = stoll(n);
        int len = n.size();

        vector<long long> candidates;

        // Boundary candidates
        candidates.push_back(pow10(len) + 1);
        candidates.push_back(pow10(len - 1) - 1);

        // Take the first half
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Try prefix - 1, prefix, prefix + 1
        for (long long p = prefix - 1; p <= prefix + 1; p++) {
            string left = to_string(p);
            string pal = left;

            // Mirror the first half
            int start = (len % 2 == 0) ? left.size() - 1
                                       : left.size() - 2;

            for (int i = start; i >= 0; i--) {
                pal += left[i];
            }

            candidates.push_back(stoll(pal));
        }

        long long answer = -1;

        for (long long candidate : candidates) {
            if (candidate == original) {
                continue;
            }

            if (answer == -1 ||
                abs(candidate - original) < abs(answer - original) ||
                (abs(candidate - original) == abs(answer - original) &&
                 candidate < answer)) {
                answer = candidate;
            }
        }

        return to_string(answer);
    }

private:
    long long pow10(int power) {
        long long result = 1;

        while (power--) {
            result *= 10;
        }

        return result;
    }
};