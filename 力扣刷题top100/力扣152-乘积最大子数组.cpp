#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����
//��ʱ�� 187 / 188 ��ͨ����������
//�������һ��������1�Ƚ϶࣬�����Ż�������Ϊ1�����֣����ٿ��������飬��Ϊ��������һ�����ִ���һ����
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];
//         for (int i = 0; i < len; ++ i) {

//             int sum = nums[i];
//             res = max(res, sum); //�п��ܵ���nums������
//             if (nums[i] == 1) //����1
//                 continue;
//             for (int j = i + 1; j < len; ++ j) {
//                 sum *= nums[j];
//                 res = max(res, sum);
//             }
//         }
//         return res;
//     }
// };

//�ο��ٷ��Ķ�̬�滮
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector <int> maxF(nums.size(), nums[0]), minF(nums.size(), nums[0]); // �൱�ڸ���ֵ������һ����Ԫ�ظ�ֵ�������Լ�Ϊ�����
        vector <int> maxF(nums), minF(nums); // �൱�ڸ���ֵ������һ����Ԫ�ظ�ֵ����
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};


int main() {

	system("pause");
	return 0;
}