#include<iostream>
#include<vector>

using namespace std;

// //暴力法
// //超时了  201 / 209 个通过测试用例
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = -10001;
//         //memo[i][j] 表示nums[i,j]中最大的和的连续子数组
//         vector<vector<int>> memo(len, vector<int>(len, 0));

//         for (int i = 0; i < len; ++ i) {
//             memo[i][i] = nums[i];
//             res = max(res, memo[i][i]);
//         }

//         for (int i = 0; i < len; ++ i) {
//             for (int j = i + 1; j < len; ++ j) {
//                 memo[i][j] = memo[i][j - 1] + nums[j];
//                 res = max(res, memo[i][j]);
//             }
//         }
//         return res;
//     }

// };


// //动态规划，重新定义数组,一维数组即可
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];

//         //memo[i] 表示nums[]以i结尾的最大的和
//         vector<int> memo(len, 0);
//         memo[0] = nums[0];

//         for (int i = 1; i < len; ++ i) {
//             memo[i] = max(memo[i - 1] + nums[i], nums[i]);
//             res = max(res, memo[i]);
//         }

//         return res;
//     }
// };

//动态规划，使用两个变量代替一维数组，因为此刻状态之和上一时刻有关
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];

        //memo[i] 表示nums[]以i结尾的最大的和
        int pre = nums[0];

        for (int i = 1; i < len; ++i) {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
        }

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}