class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_at = 10001;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            buy_at = min(buy_at, prices[i]);
            max_profit = max(max_profit, prices[i] - buy_at);
        }

        return max_profit;
    }
};
