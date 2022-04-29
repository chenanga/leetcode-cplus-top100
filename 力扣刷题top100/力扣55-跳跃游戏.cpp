#include<iostream>
#include<vector>

using namespace std;

// //暴力法  169 / 170 个通过测试用例
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int len = nums.size();

//         //memo[i]表示是否可以从前面到达该地方
//         vector<bool> memo(len, false);
//         memo[0] = true;

//         for (int i = 0; i < len; ++ i) {
//             if (memo[i] == true) {

//                 for (int j = i + 1; j < min(i + nums[i] + 1 , len); ++ j) {
//                     memo[j] = true;
//                 }
//             }
//         }
//         return memo[len-1];
//     }
// };

//暴力法  优化，用一个变量记录该索引之前都可到达，都为true，不需要再设置，后续
//能通过，但是比较耗时
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int len = nums.size();

//         //memo[i]表示是否可以从前面到达该地方
//         vector<bool> memo(len, false);
//         memo[0] = true;
//         int max_step = 0; //代表该索引之前的全部能到达
//         for (int i = 0; i < len; ++ i) {
//             if (memo[i] == true) {

//                 for (int j = max_step + 1; j < min(i + nums[i] + 1 , len); ++ j) {
//                     if (memo[j] == false)
//                         memo[j] = true;
//                 }
//                 max_step = min(i + nums[i] + 1 , len) - 1;
//             }
//         }
//         return memo[len-1];
//     }
// };

//参考官方题解
//只维护一个能到达的最远位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int max_pos = 0; //代表该索引以及之前的全部能到达
        for (int i = 0; i < len; ++i)
            if (i <= max_pos) {
                max_pos = max(max_pos, i + nums[i]);
                if (max_pos >= len - 1)
                    return true;
            }

        return false;
    }
};

// //大佬题解
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int k = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (i > k) return false;
//             k = max(k, i + nums[i]);
//         }
//         return true;
//     }
// };



int main() {

	system("pause");
	return 0;
}