#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// //ֻ�е�һ�������������еĵ�һ����������²Ż�����ڲ�ѭ��
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

//             //ֻ�е�һ�������������еĵ�һ����������²Ż�����ڲ�ѭ��
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

// //�޸���forѭ����332ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums)
//             num_set.insert(num);

//         int res = 0;
//         for (const int& num : nums) {
//             int count = 1;

//             //ֻ�е�һ�������������еĵ�һ����������²Ż�����ڲ�ѭ��
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

// //�޸���num_set.findΪcount,��res���·ŵ�if����  436 ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> num_set;
//         for (const int& num : nums)
//             num_set.insert(num);

//         int res = 0;
//         for (const int& num : nums) {

//             //ֻ�е�һ�������������еĵ�һ����������²Ż�����ڲ�ѭ��
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


//�޸���forѭ����332ms
//forѭ��ֱ����nums_set�������ظ��������
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums)
            num_set.insert(num);

        int res = 0;
        for (const int& num : num_set) {
            int count = 1;

            //ֻ�е�һ�������������еĵ�һ����������²Ż�����ڲ�ѭ��
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