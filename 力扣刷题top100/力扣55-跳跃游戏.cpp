#include<iostream>
#include<vector>

using namespace std;

// //������  169 / 170 ��ͨ����������
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int len = nums.size();

//         //memo[i]��ʾ�Ƿ���Դ�ǰ�浽��õط�
//         vector<bool> memo(len, false);
//         memo[0] = true;

//         for (int i = 0; i < len; ++ i) {
//             if (memo[i] == true) {

//                 for (int j = i + 1; j < min(i + nums[i] + 1 , len); ++ j) {
//                     memo[j] = true;
//                 }
//             }
//         }
//         return memo[len-1];
//     }
// };

//������  �Ż�����һ��������¼������֮ǰ���ɵ����Ϊtrue������Ҫ�����ã�����
//��ͨ�������ǱȽϺ�ʱ
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int len = nums.size();

//         //memo[i]��ʾ�Ƿ���Դ�ǰ�浽��õط�
//         vector<bool> memo(len, false);
//         memo[0] = true;
//         int max_step = 0; //���������֮ǰ��ȫ���ܵ���
//         for (int i = 0; i < len; ++ i) {
//             if (memo[i] == true) {

//                 for (int j = max_step + 1; j < min(i + nums[i] + 1 , len); ++ j) {
//                     if (memo[j] == false)
//                         memo[j] = true;
//                 }
//                 max_step = min(i + nums[i] + 1 , len) - 1;
//             }
//         }
//         return memo[len-1];
//     }
// };

//�ο��ٷ����
//ֻά��һ���ܵ������Զλ��
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int max_pos = 0; //����������Լ�֮ǰ��ȫ���ܵ���
        for (int i = 0; i < len; ++i)
            if (i <= max_pos) {
                max_pos = max(max_pos, i + nums[i]);
                if (max_pos >= len - 1)
                    return true;
            }

        return false;
    }
};

// //�������
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int k = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (i > k) return false;
//             k = max(k, i + nums[i]);
//         }
//         return true;
//     }
// };



int main() {

	system("pause");
	return 0;
}