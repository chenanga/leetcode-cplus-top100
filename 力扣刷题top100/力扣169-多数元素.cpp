#include<iostream>
#include<vector>

using namespace std;

// //�����ȡ�м�Ԫ�أ���Ϊһ�����룬���Է����м�Ԫ�ؼ���
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         return nums[nums.size() / 2];
//     }
// };

// //��ϣ��
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

// //Ħ��ͶƱ��
//ִ����ʱ��16 ms, ������ C++ �ύ�л�����70.37%���û�
// //��scoreΪ0ʱ��ȡ��ǰԪ��Ϊ��������+1������Ԫ��-1
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


//Ħ��ͶƱ��
//��scoreΪ0ʱ��ȡ��ǰԪ��Ϊ��������+1������Ԫ��-1
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

// //�ٷ�Ħ��ͶƱ�� �ⷨ��
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