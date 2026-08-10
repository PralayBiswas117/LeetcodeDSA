class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);
        string word = "";

        for (char c : s) {
            if (c == ' ') {
                int pos = word.back() - '0';
                word.pop_back();
                words[pos] = word;
                word = "";
            } else {
                word += c;
            }
        }

        int pos = word.back() - '0';
        word.pop_back();
        words[pos] = word;

        string ans = "";
        for (int i = 1; i < 10; i++) {
            if (!words[i].empty()) {
                if (!ans.empty()) ans += " ";
                ans += words[i];
            }
        }

        return ans;
    }
};