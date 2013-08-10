class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0;
        if (prices.size() < 2) {
            return 0;
        }
        int in = prices[0];
        int out;
        bool find_in = true;
        for (int i = 1; i < prices.size(); i++) {
            if (find_in) {
                if (prices[i] < in) {
                    in = prices[i];
                } else {
                    out = prices[i];
                    find_in = false;
                }
            } else if (prices[i] > out) {
                out = prices[i];
            } else {
                profit += out - in;
                in = prices[i];
                find_in = true;
            }
        }
        if (!find_in) {
            profit += out - in;
        }
        return profit;
    }
};
