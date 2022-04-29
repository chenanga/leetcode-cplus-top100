#include<iostream>
#include<vector>

using namespace std;

// //������
// //��ʱ��  201 / 209 ��ͨ����������
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = -10001;
//         //memo[i][j] ��ʾnums[i,j]�����ĺ͵�����������
//         vector<vector<int>> memo(len, vector<int>(len, 0));

//         for (int i = 0; i < len; ++ i) {
//             memo[i][i] = nums[i];
//             res = max(res, memo[i][i]);
//         }

//         for (int i = 0; i < len; ++ i) {
//             for (int j = i + 1; j < len; ++ j) {
//                 memo[i][j] = memo[i][j - 1] + nums[j];
//                 res = max(res, memo[i][j]);
//             }
//         }
//         return res;
//     }

// };


// //��̬�滮�����¶�������,һά���鼴��
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];

//         //memo[i] ��ʾnums[]��i��β�����ĺ�
//         vector<int> memo(len, 0);
//         memo[0] = nums[0];

//         for (int i = 1; i < len; ++ i) {
//             memo[i] = max(memo[i - 1] + nums[i], nums[i]);
//             res = max(res, memo[i]);
//         }

//         return res;
//     }
// };

//��̬�滮��ʹ��������������һά���飬��Ϊ�˿�״̬֮����һʱ���й�
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];

        //memo[i] ��ʾnums[]��i��β�����ĺ�
        int pre = nums[0];

        for (int i = 1; i < len; ++i) {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
        }

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}