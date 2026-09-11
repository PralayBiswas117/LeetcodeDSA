class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                      vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        // Avoid visiting beginWord again
        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord)
                return steps;

            // Try changing every character
            for (int i = 0; i < word.length(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.find(word) != st.end()) {

                        // Mark as visited
                        st.erase(word);

                        q.push({word, steps + 1});
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};