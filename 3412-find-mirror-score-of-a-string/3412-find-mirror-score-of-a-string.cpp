class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long totalScore = 0;

        // map each character to a vector storing its indices
        unordered_map<char, vector<int>> charPositions;

        for (int i = 0; i < n; i++) 
        {
            char mirrorChar = ('z'-s[i])+'a';

            // if we have encountered a character and it is unmarked 
            if (charPositions[mirrorChar].size() > 0) 
            {
                int lastPos = charPositions[mirrorChar].back();
                charPositions[mirrorChar].pop_back();  //last element is the closest mirror element / mark it
                totalScore += (i - lastPos);
            } 
            else 
            {
                charPositions[s[i]].push_back(i);  // if it is the first occurance - unmarked
            }
        }

        return totalScore;
    }
};