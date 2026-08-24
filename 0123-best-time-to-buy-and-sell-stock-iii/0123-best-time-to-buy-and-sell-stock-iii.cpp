class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> suffixProfit(n, 0);

        int maxPrice = prices[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            suffixProfit[i] = maxPrice - prices[i];
        }

        int minPrice = prices[0];
        int prefixProfit = 0;
        int answer = suffixProfit[0];

        for (int i = 1; i < n; i++) {
            prefixProfit = max(prefixProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
            answer = max(answer, prefixProfit + suffixProfit[i]);
        }

        return answer;
    }
};