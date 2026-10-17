class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size(); 
        int count = 0; 
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> firstSeen; 
            int j; 
            
            for (j = i; j < n; j++) {
                char curr = word[j]; 
                
                if (firstSeen.find(curr) != firstSeen.end()) {
                    if ((j - firstSeen[curr] + 1) >= 4) {
                        count++;     // Found a valid non-overlapping substring
                        break;       // Move to the next one
                    }
                } else {
                    firstSeen[curr] = j;  // Mark first occurrence
                }
            }
            
            i = j; // Move the outer index to the end of this substring
        }
        
        return count; 
    }
};