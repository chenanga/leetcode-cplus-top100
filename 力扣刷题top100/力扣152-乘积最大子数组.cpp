#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//暴力
//超时了 187 / 188 个通过测试用例
//由于最后一个用例种1比较多，所以优化，对于为1的数字，不再看他的数组，因为和她的上一个数字答案是一样的
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];
//         for (int i = 0; i < len; ++ i) {

//             int sum = nums[i];
//             res = max(res, sum); //有可能单个nums是最大的
//             if (nums[i] == 1) //跳过1
//                 continue;
//             for (int j = i + 1; j < len; ++ j) {
//                 sum *= nums[j];
//                 res = max(res, sum);
//             }
//         }
//         return res;
//     }
// };

//参考官方的动态规划
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector <int> maxF(nums.size(), nums[0]), minF(nums.size(), nums[0]); // 相当于赋初值，给第一个给元素赋值本身，可以简化为下面的
        vector <int> maxF(nums), minF(nums); // 相当于赋初值，给第一个给元素赋值本身
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};


int main() {

	system("pause");
	return 0;
}