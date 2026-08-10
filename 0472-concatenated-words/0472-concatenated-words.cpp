class TrieNode {
public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->end = true;
    }

    bool dfs(string &word, int index, int count, vector<int> &memo) {
        if (index == word.size())
            return count >= 2;

        if (memo[index] != -1)
            return memo[index];

        TrieNode* node = root;

        for (int i = index; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (!node->child[idx])
                break;

            node = node->child[idx];

            if (node->end) {
                if (dfs(word, i + 1, count + 1, memo))
                    return memo[index] = true;
            }
        }

        return memo[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string &w : words)
            if (!w.empty())
                insert(w);

        vector<string> ans;

        for (string &w : words) {
            if (w.empty()) continue;
            vector<int> memo(w.size(), -1);
            if (dfs(w, 0, 0, memo))
                ans.push_back(w);
        }

        return ans;
    }
};