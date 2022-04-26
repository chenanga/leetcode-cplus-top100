#include<iostream>
#include<vector>

using namespace std;

//二分查找到这个元素，然后向前向后拓展，找到第一次位置和最后一次位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1, mid;
        if (len < 1 || target < nums[left] || target > nums[right]) return { -1, -1 };

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                left = mid + 1;
            else // nums[mid] > target
                right = mid - 1;
        }
        if (left > right) return { -1, -1 };

        left = mid, right = mid;
        while (left >= 0 && nums[left] == nums[mid])
            --left;
        while (right < len && nums[right] == nums[mid])
            ++right;

        return { left + 1, right - 1 };
    }
};


//官方思想查找第一个等于target和第一个大于target的索引，后面的索引减1
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

int main() {

	system("pause");
	return 0;
}