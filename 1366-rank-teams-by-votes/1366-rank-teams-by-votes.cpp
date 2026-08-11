class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();

        unordered_map<char, vector<int>> cnt;

        for (char c : votes[0])
            cnt[c] = vector<int>(m, 0);

        for (string &vote : votes) {
            for (int i = 0; i < m; i++) {
                cnt[vote[i]][i]++;
            }
        }

        vector<char> teams(votes[0].begin(), votes[0].end());

        sort(teams.begin(), teams.end(), [&](char a, char b) {
            for (int i = 0; i < m; i++) {
                if (cnt[a][i] != cnt[b][i])
                    return cnt[a][i] > cnt[b][i];
            }
            return a < b;
        });

        return string(teams.begin(), teams.end());
    }
};