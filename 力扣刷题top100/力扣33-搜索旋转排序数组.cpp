#include<iostream>
#include<vector>

using namespace std;

//暴力解法
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int len = nums.size();
//         for (int i = 0; i < len; ++ i) {
//             if (nums[i] == target)
//                 return i;
//         }

//         return -1;
//     }
// };

// //二分查找  差了一些细节
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int len = nums.size();
//         if (len == 1) return (nums[0] == target) ? 0 : -1;
//         int left = 0, right = len - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target)
//                 return mid;
//             if (left == right) return -1;
//             if (nums[mid] > nums[left]) {//左边升序排列
//                 //先判断是否在左边，如果不在去右边
//                 if (target >= nums[left] && target <= nums[mid])
//                     right = mid;
//                 else 
//                     left = mid + 1;

//             }
//             else {//右边升序排列
//                 //先判断是否在you边，如果不在去zuo边
//                 if (target >= nums[mid + 1] && target <= nums[right])
//                     left = mid + 1;
//                 else 
//                     right = mid;
//             }

//         }

//         return -1;
//     }
// };

//二分查找， right = mid - 1;  这样避免找不到时候一直循环，再用left==right判断返回
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 1) return (nums[0] == target) ? 0 : -1;
        int left = 0, right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > nums[left]) {//左边升序排列
                //先判断是否在左边，如果不在去右边
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;

            }
            else {//右边升序排列
                //先判断是否在you边，如果不在去zuo边
                if (target >= nums[mid + 1] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }

        }

        return -1;
    }
};
int main() {

	system("pause");
	return 0;
}