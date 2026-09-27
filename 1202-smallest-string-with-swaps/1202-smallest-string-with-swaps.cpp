struct DSU {
    vector<int> parent, rank;
    vector<array<int,26>> freq_map;

    DSU(int n, const string& s)
        : parent(n), rank(n,0), freq_map(n) {

        iota(parent.begin(), parent.end(), 0);

        for(int i = 0; i < n; i++)
            freq_map[i][s[i]-'a'] = 1;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y) return false;

        if(rank[x] < rank[y])
            swap(x,y);

        parent[y] = x;

        for(int i = 0; i < 26; i++)
            freq_map[x][i] += freq_map[y][i];

        if(rank[x] == rank[y])
            rank[x]++;

        return true;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU d(n, s);

        for(auto& p : pairs)
            d.unite(p[0], p[1]);

        for(int i = 0; i < n; i++) {
            //find group id using find
            int root = d.find(i);
            //get the freq map for the group
            auto& fm = d.freq_map[root];
            //iterate skipping zeros, and decrease freq of first non zero guy
            for(int j = 0; j < 26; j++) {
                if(fm[j]) {
                    s[i] = 'a' + j;
                    fm[j]--;
                    break;
                }
            }
        }

        return s;
    }
};