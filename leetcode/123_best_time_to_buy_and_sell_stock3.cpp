class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2) {
            return 0;
        }
        // construct first profits
        vector<int> first(prices.size(), 0);
        int min_price = prices[0];
        first[0] = 0;
        for (int i = 1; i < first.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            first[i] = max(first[i-1], prices[i] - min_price);
        }
        
        // construct second profits
        vector<int> second(prices.size(), 0);
        int max_price = prices[second.size()-1];
        second[second.size()-1] = 0;
        for (int i = second.size()-2; i >= 0; i--) {
            if (prices[i] > max_price) {
                max_price = prices[i];
            }
            second[i] = max(second[i+1], max_price - prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 1; i < first.size()-1; i++) {
            max_profit = max(first[i]+second[i+1], max_profit);
        }
        max_profit = max(first.back(), max_profit);
        
        return max_profit;
    }
};
