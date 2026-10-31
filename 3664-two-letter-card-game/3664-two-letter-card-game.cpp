class Solution {
public:
    int score(vector<string>& cards, char x) {
        // Groups:
        // leftgroup : cards where s[0] == x
        // rightgroup: cards where s[1] == x
        // XXCHAR    : cards where both characters are x
        map<int, int> leftgroup;
        map<int, int> rightgroup;
        int XXCHAR = 0;

        for (auto &a : cards) {
            if (a[0] == x && a[1] == x) {
                XXCHAR++;
            } else if (a[0] == x) {
                leftgroup[a[1] - 'a']++;
            } else if (a[1] == x) {
                rightgroup[a[0] - 'a']++;
            }
        }

        // Max-heaps for pairing within left/right groups
        priority_queue<int> lpq;
        priority_queue<int> rpq;

        for (auto &a : leftgroup) lpq.push(a.second);
        for (auto &a : rightgroup) rpq.push(a.second);

        int ans = 0;

        // Pair cards inside left group
        while (lpq.size() > 1) {
            int a = lpq.top(); lpq.pop();
            int b = lpq.top(); lpq.pop();
            a--; b--;                // form 1 pair
            if (a > 0) lpq.push(a);
            if (b > 0) lpq.push(b);
            ans++;
        }

        // Pair cards inside right group
        while (rpq.size() > 1) {
            int a = rpq.top(); rpq.pop();
            int b = rpq.top(); rpq.pop();
            a--; b--;                // form 1 pair
            if (a > 0) rpq.push(a);
            if (b > 0) rpq.push(b);
            ans++;
        }

        // Collect leftovers from PQ
        int totalLeftFreq = 0;
        while (!lpq.empty()) {
            totalLeftFreq += lpq.top();
            lpq.pop();
        }
        int totalRightFreq = 0;
        while (!rpq.empty()) {
            totalRightFreq += rpq.top();
            rpq.pop();
        }

        int ansTillNow = ans;

        // First, pair leftover LEFT chars with XX
        int c = min(totalLeftFreq, XXCHAR);
        ans += c;
        XXCHAR -= c;

        // Then, pair leftover RIGHT chars with XX
        if (XXCHAR > 0) {
            int c = min(totalRightFreq, XXCHAR);
            ans += c;
            XXCHAR -= c;
        }

        // Special case:
        // If XX still remains, we can "improve" some already-formed pairs
        // Example: 1 ac + 1 ab paired, 2 aa remain.
        // Better: (aa + ac) + (aa + ab) → so ans += min(ansTillNow, XXCHAR/2)
        if (XXCHAR > 0) {
            ans += min(ansTillNow, XXCHAR / 2);
        }

        return ans;
    }
};