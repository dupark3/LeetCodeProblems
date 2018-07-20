#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t prices_size = prices.size();
        
        if (prices_size <= 1){
            return 0;
        }

        int max_profit = 0;

        for (int i = 0; i != prices_size; ++i){
            for (int j = i + 1; j != prices_size; ++j){
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }

        return max_profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 3, 5, 6, 1, 2, 0};
    vector<int> prices2 = {};
    vector<int> prices3 = {7, 6, 5, 4, 3, 1};
    vector<int> prices4 = {8, 1000, 1, 7, 1, 3, 5, 10, -1, 6, 1, 2, -100000};

    cout << solution.maxProfit(prices) << endl;
    cout << solution.maxProfit(prices2) << endl;
    cout << solution.maxProfit(prices3) << endl;
    cout << solution.maxProfit(prices4) << endl;
    return 0;
}