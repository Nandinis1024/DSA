
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//Brute Force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int difference, maxProfit = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(prices[j] > prices[i]){
                    difference = prices[j] - prices[i];
                    maxProfit = max(difference, maxProfit);
                }
            }
        }
        return maxProfit;
    }
};

//optimal solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX, maxPro = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < min){
                min = prices[i];
            }
        maxPro = max(maxPro, prices[i] - min);

        }
        return maxPro;
    }
};
