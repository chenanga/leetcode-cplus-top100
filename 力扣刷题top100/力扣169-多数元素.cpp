#include<iostream>
#include<vector>

using namespace std;

// //排序后，取中间元素，因为一定过半，所以返回中间元素即可
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         return nums[nums.size() / 2];
//     }
// };

// //哈希表
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         unordered_map<int,int> hashMap;
//         int res = 0;
//         for (int i = 0; i < nums.size(); ++ i) {
//             hashMap[nums[i]] ++;
//             if (hashMap[res] < hashMap[nums[i]])
//                 res = nums[i];
//         }

//         return res;
//     }
// };

// //摩尔投票法
//执行用时：16 ms, 在所有 C++ 提交中击败了70.37%的用户
// //当score为0时候，取当前元素为正样本，+1，其他元素-1
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int score = 0, candidate = nums[0];
//         for (int i = 0; i < nums.size(); ++ i) {
//             if (score == 0) {
//                 candidate = nums[i];
//             }
//             if (nums[i] == candidate)
//                 ++ score;
//             else
//                 -- score;
//         }

//         return candidate;
//     }
// };


//摩尔投票法
//当score为0时候，取当前元素为正样本，+1，其他元素-1
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int score = 0, candidate = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (score == 0) {
                candidate = nums[i];
                score = 1;
            }
            else {
                if (nums[i] == candidate)
                    ++score;
                else
                    --score;
            }
        }
        return candidate;
    }
};

// //官方摩尔投票法 解法，
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int candidate = -1;
//         int count = 0;
//         for (int num : nums) {
//             if (num == candidate)
//                 ++count;
//             else if (--count < 0) {
//                 candidate = num;
//                 count = 1;
//             }
//         }
//         return candidate;
//     }
// };


int main() {

	system("pause");
	return 0;
}