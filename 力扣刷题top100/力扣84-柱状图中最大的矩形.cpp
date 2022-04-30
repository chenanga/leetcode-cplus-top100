#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// //暴力法，枚举每个矩形向左右延申的最大面积
// //87 / 96 个通过测试用例
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int len = heights.size();
//         int res = 0;
//         for (int i = 0; i < len; ++ i) {

//             int left = i - 1, right = i + 1;

//             while (left >= 0 && heights[left] >= heights[i])
//                 -- left;

//             while (right < len && heights[right] >= heights[i])
//                 ++ right;

//             int width =  right - left - 1;
//             res = max(res, width * heights[i]);
//         }
//         return res;

//     }
// };

// //使用单调栈优化，两遍遍历
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int len = heights.size();

//         stack<int> stk;
//         vector<int> left(len, 0), right(len, 0);

//         //分别确定每个柱子的左边界和右边界
//         for (int i = 0; i < len; ++ i) {
//             while (!stk.empty() && heights[stk.top()] >= heights[i]) 
//                 stk.pop();
//             left[i] = (stk.empty() ? -1 : stk.top());
//             stk.push(i);
//         }

//         stk = stack<int>();
//         for (int i = len - 1; i >= 0; -- i) {
//             while (!stk.empty() && heights[stk.top()] >= heights[i]) 
//                 stk.pop();
//             right[i] = (stk.empty() ? len : stk.top());
//             stk.push(i);   
//         }

//         int res = 0;
//         for (int i = 0; i < len; ++ i) 
//             res = max(res, (right[i] - left[i] - 1) * heights[i]);

//         return res;

//     }
// };

//使用单调栈优化,一遍遍历
//当元素出栈时候，说明出栈位置的高度大于等于当前位置的高度，也是第一个小于出栈位置的元素，所以right[c出] = 当前
//最后还会有部分元素没有出栈，这些元素都是右边界为len的
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();

        stack<int> stk;
        vector<int> left(len, 0), right(len, len);

        //分别确定每个柱子的左边界和右边界
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < len; ++i)
            res = max(res, (right[i] - left[i] - 1) * heights[i]);

        return res;

    }
};

int main() {

	system("pause");
	return 0;
}