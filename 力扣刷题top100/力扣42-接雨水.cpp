#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// //暴力法
// //对于每一个元素求他能放雨水的值
// //319 / 321 个通过测试用例   超时了
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, len = height.size();
//         if (len <= 1) return 0;

//         for (int i = 0; i < len; ++i) {
//             int left = i - 1, right = i + 1;
//             int left_max = 0, right_max = 0; //表示当前元素左边和右边的最大值
//             while (left >= 0) {
//                 left_max = max(left_max, height[left]);
//                 -- left;
//             }
//             while (right < len) {
//                 right_max = max(right_max, height[right]);
//                 ++ right;
//             }
//             res += max(min(left_max, right_max) - height[i], 0); 
//         }
//         return res;
//     }
// };

//暴力法，优化
//如果用一个辅助的数组记录一下每个元素左右的最大值，那么就剩去遍历了
/*
如果已经知道每个位置两边的最大高度，则可以在 O(n) 的时间内得到能接的雨水总量。使用动态规划的方法，可以在O(n) 的时间内预处理得到每个位置两边的最大高度。

创建两个长度为 n 的数组 leftMax 和rightMax。对于 i<n，leftMax[i] 表示下标 i 及其左边的位置中，height 的最大高度，rightMax[i] 表示下标 i 及其右边的位置中，height 的最大高度。
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, len = height.size();
//         if (len <= 1) return 0;
//         vector<int> left_max(len, 0), right_max(len, 0);

//         left_max[0] = height[0];
//         right_max[len - 1] = height[len - 1];

//         for (int i = 1; i < len; ++ i) 
//             left_max[i] = max(height[i], left_max[i - 1]);

//         for (int i = len - 2; i >= 0; -- i) 
//             right_max[i] = max(height[i], right_max[i + 1]);


//         for (int i = 1; i < len - 1; ++ i) 
//             res += max(min(left_max[i - 1], right_max[i + 1]) - height[i], 0); 

//         return res;
//     }
// };
// /* 打印调试语句
//             // cout << "i = " << i << " , left_max[i - 1] = " << left_max[i - 1] << " , right_max[i + 1] = " << right_max[i + 1] << endl;
// */


// 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, len = height.size();
        if (len <= 1) return 0;
        stack<int> aux; //单调栈，存入索引

        for (int i = 0; i < len; ++i) {

            while (!aux.empty() && height[i] > height[aux.top()]) {
                int top = aux.top();
                aux.pop();

                if (aux.empty()) break;
                int left = aux.top();

                int trap_width = i - left + 1 - 2; //[i,left]共有i-left+1个格子，除去左右边界
                int trap_height = min(height[left], height[i]) - height[top];
                res += trap_width * trap_height;
            }
            aux.push(i);
        }

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}