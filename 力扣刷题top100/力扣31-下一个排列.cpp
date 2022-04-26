#include<iostream>
#include<vector>

using namespace std;

// //思路差不多对了，但是考虑的不是太太全面  
//188 / 265
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int len = nums.size();
//         if (len == 1) return ;
//         int i = len - 1;
//         //从最后两位开始往前，尝试交换，如果交换后大于原先的，则停止
//         for ( ; i >= 1; -- i) {

//             if (nums[i - 1] < nums[i]) {
//                 //把后面排序
//                 vector<int>::iterator iter = nums.begin();

//                 for (int j = 0; j < i; ++ j)
//                     iter ++;
//                 swap(nums[i - 1], nums[i]);
//                 sort(iter, nums.end());

//                 break;
//             } 
//             swap(nums[i - 1], nums[i]);


//         }
//         if (i == 0) {
//             //需要反转
//             sort(nums.begin(), nums.end());
//         }
//         return;
//     }
// };


//看官方题解后的解答
/*
以排列 [4,5,2,6,3,1] 为例：

我们能找到的符合条件的一对「较小数」与「较大数」的组合为 2 与 3，满足「较小数」尽量靠右，而「较大数」尽可能小。

当我们完成交换后排列变为 [4,5,3,6,2,1]，此时我们可以重排「较小数」右边的序列，序列变为 [4,5,3,1,2,6]。

具体地，我们这样描述该算法，对于长度为 n 的排列 a：

首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i]<a[i+1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。

如果找到了顺序对，那么在区间 [i+1,n)中从后向前查找第一个元素 j 满足 a[i]<a[j]。这样「较大数」即为 a[j]。

交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n)使其变为升序，而无需对该区间进行排序。

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return;
        int i = len - 1;
        //从最后两位开始往前，尝试当前位大于上一位，则停止
        for (; i >= 1; --i) {

            if (nums[i - 1] < nums[i]) {
                //从后往前找第一个大于nums[i-1], 交换
                for (int j = len - 1; j >= i; --j) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        break;
                    }
                }

                //后面一定为降序排列，所以直接反转
                reverse(nums.begin() + i, nums.end());
                break;
            }

        }
        if (i == 0)
            reverse(nums.begin(), nums.end());

        return;
    }
};
// c++ stl库实现         next_permutation(nums.begin(),nums.end()); // STL功能和题目描述一致

// //官方题解
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 2;
//         while (i >= 0 && nums[i] >= nums[i + 1]) {
//             i--;
//         }
//         if (i >= 0) {
//             int j = nums.size() - 1;
//             while (j >= 0 && nums[i] >= nums[j]) {
//                 j--;
//             }
//             swap(nums[i], nums[j]);
//         }
//         reverse(nums.begin() + i + 1, nums.end());
//     }
// };



int main() {

	system("pause");
	return 0;
}