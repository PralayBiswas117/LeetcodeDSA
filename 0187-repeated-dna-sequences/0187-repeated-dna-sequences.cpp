class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.length();
        if(n < 10) return {};

        unordered_set<int> seen;
        unordered_set<string> result;

        unordered_map<char, int> mpp = {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3}
        };

        int k = 10;
        int rep = 0;

        // Build first window
        for(int i = 0; i < k; i++) {
            rep = rep * 4 + mpp[s[i]];
        }

        seen.insert(rep);

        // Calculate 4^(k-1)
        int highestPower = 1;
        for(int i = 1; i < k; i++) {
            highestPower *= 4;
        }

        // Slide the window
        for(int i = k; i < n; i++) {

            // Remove leftmost character
            rep = rep - highestPower * mpp[s[i - k]];

            // Shift left
            rep = rep * 4;

            // Add new character
            rep = rep + mpp[s[i]];

            if(seen.count(rep)) {
                result.insert(s.substr(i - k + 1, k));
            }

            seen.insert(rep);
        }

        return vector<string>(result.begin(), result.end());
    }
};