#include<iostream>
#include<vector>

using namespace std;

// //暴力法超时 199 / 211 个通过测试用例
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;

//         for (int i = 0; i < prices.size(); ++ i) {
//             for (int j = i + 1; j < prices.size(); ++ j) {
//                 res = max(res, prices[j] - prices[i]);
//             }
//         }
//         return res;
//     }
// };


// //暴力优化,定义一个当前买入最小值，如果比最小值大，说明肯定不是最优，直接看下一个
// //211 / 211 个通过测试用例, 最后一个没通过
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         int min_prices = INT_MAX;
//         for (int i = 0; i < prices.size(); ++ i) {
//             if (prices[i] < min_prices) {
//                 min_prices = prices[i];
//                 for (int j = i + 1; j < prices.size(); ++ j) 
//                     res = max(res, prices[j] - prices[i]);

//             }
//         }
//         return res;
//     }
// };

//继续暴力优化
//如果有一个数组存放i位置以后的最大值，就不用遍历了
/*
执行用时：124 ms, 在所有 C++ 提交中击败了24.41%的用户
内存消耗：94.8 MB, 在所有 C++ 提交中击败了20.78%的用户
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         int min_prices = INT_MAX;

//         //存放i以及i位置以后的最大数
//         vector<int> memo(prices.size(), 0);
//         memo[prices.size() - 1] = prices[prices.size() - 1];
//         for (int i = prices.size() - 2; i >= 0; -- i) 
//             memo[i] = max(memo[i + 1], prices[i]);

//         for (int i = 0; i < prices.size(); ++ i) {
//             if (prices[i] < min_prices) {
//                 min_prices = prices[i];
//                 res = max(res, memo[i] - prices[i]);

//             }
//         }
//         return res;
//     }
// };

/*
执行用时：104 ms, 在所有 C++ 提交中击败了60.86%的用户
内存消耗：95 MB, 在所有 C++ 提交中击败了15.81%的用户
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;

//         //存放i以及i位置以后的最大数
//         vector<int> memo(prices.size(), 0);
//         memo[prices.size() - 1] = prices[prices.size() - 1];
//         for (int i = prices.size() - 2; i >= 0; -- i) 
//             memo[i] = max(memo[i + 1], prices[i]);

//         for (int i = 0; i < prices.size(); ++ i)    
//             res = max(res, memo[i] - prices[i]);

//         return res;
//     }
// };

//官方思路
/*
在题目中，我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_prices = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            res = max(res, prices[i] - min_prices);
            min_prices = min(min_prices, prices[i]);
        }

        return res;
    }
};


int main() {

	system("pause");
	return 0;
}