#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// //只有当一个数是连续序列的第一个数的情况下才会进入内层循环
// //360ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums)
//             num_set.insert(num);

//         int res = 0;
//         for (int i = 0; i < nums.size(); ++ i) {
//             int count = 1;

//             //只有当一个数是连续序列的第一个数的情况下才会进入内层循环
//             if (num_set.find(nums[i] - 1) == num_set.end()){
//                 int cur_num = nums[i];
//                 while (num_set.find(++ cur_num) != num_set.end()) 
//                     ++ count;    
//             }
//             res = max(res, count);
//         }

//         return res;
//     }
// };

// //修改了for循环，332ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums)
//             num_set.insert(num);

//         int res = 0;
//         for (const int& num : nums) {
//             int count = 1;

//             //只有当一个数是连续序列的第一个数的情况下才会进入内层循环
//             if (num_set.find(num - 1) == num_set.end()){
//                 int cur_num = num;
//                 while (num_set.find(++ cur_num) != num_set.end()) 
//                     ++ count;    
//             }
//             res = max(res, count);
//         }

//         return res;
//     }
// };

// //修改了num_set.find为count,把res更新放到if里面  436 ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums)
//             num_set.insert(num);

//         int res = 0;
//         for (const int& num : nums) {

//             //只有当一个数是连续序列的第一个数的情况下才会进入内层循环
//             if (! num_set.count(num - 1)){
//                 int count = 1;
//                 int cur_num = num;
//                 while (num_set.count(++ cur_num)) 
//                     ++ count;   
//                 res = max(res, count); 
//             }

//         }

//         return res;
//     }
// };


//修改了for循环，332ms
//for循环直接在nums_set遍历，重复的无需管
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums)
            num_set.insert(num);

        int res = 0;
        for (const int& num : num_set) {
            int count = 1;

            //只有当一个数是连续序列的第一个数的情况下才会进入内层循环
            if (num_set.find(num - 1) == num_set.end()) {
                int cur_num = num;
                while (num_set.find(++cur_num) != num_set.end())
                    ++count;
                res = max(res, count);
            }

        }

        return res;
    }
};
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums) {
//             num_set.insert(num);
//         }

//         int longestStreak = 0;

//         for (const int& num : num_set) {
//             if (!num_set.count(num - 1)) {
//                 int currentNum = num;
//                 int currentStreak = 1;

//                 while (num_set.count(currentNum + 1)) {
//                     currentNum += 1;
//                     currentStreak += 1;
//                 }

//                 longestStreak = max(longestStreak, currentStreak);
//             }
//         }

//         return longestStreak;           
//     }
// };



int main() {

	system("pause");
	return 0;
}