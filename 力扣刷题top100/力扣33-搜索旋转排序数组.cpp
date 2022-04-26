#include<iostream>
#include<vector>

using namespace std;

//�����ⷨ
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

// //���ֲ���  ����һЩϸ��
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
//             if (nums[mid] > nums[left]) {//�����������
//                 //���ж��Ƿ�����ߣ��������ȥ�ұ�
//                 if (target >= nums[left] && target <= nums[mid])
//                     right = mid;
//                 else 
//                     left = mid + 1;

//             }
//             else {//�ұ���������
//                 //���ж��Ƿ���you�ߣ��������ȥzuo��
//                 if (target >= nums[mid + 1] && target <= nums[right])
//                     left = mid + 1;
//                 else 
//                     right = mid;
//             }

//         }

//         return -1;
//     }
// };

//���ֲ��ң� right = mid - 1;  ���������Ҳ���ʱ��һֱѭ��������left==right�жϷ���
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
            if (nums[mid] > nums[left]) {//�����������
                //���ж��Ƿ�����ߣ��������ȥ�ұ�
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;

            }
            else {//�ұ���������
                //���ж��Ƿ���you�ߣ��������ȥzuo��
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