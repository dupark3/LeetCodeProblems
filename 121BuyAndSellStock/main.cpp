#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t prices_size = prices.size();
        
        if (prices_size <= 1) return 0;

        vector<int> local_maxes(prices_size + 1, 0);
        int max_price = 0, max_profit = 0; 

        for (int i = prices_size - 1; i != -1; --i){
            max_price = max(max_price, prices[i]);
            local_maxes[i] = max_price;
            max_profit = max(max_profit, local_maxes[i+1] - prices[i]);
        }

        return max_profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 3, 5, 6, 1, 2, 0};
    vector<int> prices3 = {7, 6, 5, 4, 3, 1};
    vector<int> prices4 = {8, 1000, 1, 7, 1, 3, 5, 10, -1, 6, 1, 2, 0};

    cout << solution.maxProfit(prices) << endl;
    cout << solution.maxProfit(prices3) << endl;
    cout << solution.maxProfit(prices4) << endl;
    return 0;
}