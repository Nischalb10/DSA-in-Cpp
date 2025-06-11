// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104
#include <iostream>
#include <climits>  // for INT_MAX
using namespace std;

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        minPrice = (prices[i] < minPrice) ? prices[i] : minPrice;
        profit = (prices[i] - minPrice > profit) ? prices[i] - minPrice : profit;
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int* prices = new int[n];
    cout << "Enter prices for each day:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices, n);
    cout << "Maximum profit: " << result << endl;

    delete[] prices; // clean up heap memory
    return 0;
}
