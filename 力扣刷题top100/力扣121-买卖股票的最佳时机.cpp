#include<iostream>
#include<vector>

using namespace std;

// //��������ʱ 199 / 211 ��ͨ����������
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


// //�����Ż�,����һ����ǰ������Сֵ���������Сֵ��˵���϶��������ţ�ֱ�ӿ���һ��
// //211 / 211 ��ͨ����������, ���һ��ûͨ��
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

//���������Ż�
//�����һ��������iλ���Ժ�����ֵ���Ͳ��ñ�����
/*
ִ����ʱ��124 ms, ������ C++ �ύ�л�����24.41%���û�
�ڴ����ģ�94.8 MB, ������ C++ �ύ�л�����20.78%���û�
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         int min_prices = INT_MAX;

//         //���i�Լ�iλ���Ժ�������
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
ִ����ʱ��104 ms, ������ C++ �ύ�л�����60.86%���û�
�ڴ����ģ�95 MB, ������ C++ �ύ�л�����15.81%���û�
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;

//         //���i�Լ�iλ���Ժ�������
//         vector<int> memo(prices.size(), 0);
//         memo[prices.size() - 1] = prices[prices.size() - 1];
//         for (int i = prices.size() - 2; i >= 0; -- i) 
//             memo[i] = max(memo[i + 1], prices[i]);

//         for (int i = 0; i < prices.size(); ++ i)    
//             res = max(res, memo[i] - prices[i]);

//         return res;
//     }
// };

//�ٷ�˼·
/*
����Ŀ�У�����ֻҪ��һ��������¼һ����ʷ��ͼ۸� minprice�����ǾͿ��Լ����Լ��Ĺ�Ʊ����������ġ���ô�����ڵ� i ��������Ʊ�ܵõ���������� prices[i] - minprice��
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