#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// //������
// //����ÿһ��Ԫ�������ܷ���ˮ��ֵ
// //319 / 321 ��ͨ����������   ��ʱ��
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, len = height.size();
//         if (len <= 1) return 0;

//         for (int i = 0; i < len; ++i) {
//             int left = i - 1, right = i + 1;
//             int left_max = 0, right_max = 0; //��ʾ��ǰԪ����ߺ��ұߵ����ֵ
//             while (left >= 0) {
//                 left_max = max(left_max, height[left]);
//                 -- left;
//             }
//             while (right < len) {
//                 right_max = max(right_max, height[right]);
//                 ++ right;
//             }
//             res += max(min(left_max, right_max) - height[i], 0); 
//         }
//         return res;
//     }
// };

//���������Ż�
//�����һ�������������¼һ��ÿ��Ԫ�����ҵ����ֵ����ô��ʣȥ������
/*
����Ѿ�֪��ÿ��λ�����ߵ����߶ȣ�������� O(n) ��ʱ���ڵõ��ܽӵ���ˮ������ʹ�ö�̬�滮�ķ�����������O(n) ��ʱ����Ԥ����õ�ÿ��λ�����ߵ����߶ȡ�

������������Ϊ n ������ leftMax ��rightMax������ i<n��leftMax[i] ��ʾ�±� i ������ߵ�λ���У�height �����߶ȣ�rightMax[i] ��ʾ�±� i �����ұߵ�λ���У�height �����߶ȡ�
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, len = height.size();
//         if (len <= 1) return 0;
//         vector<int> left_max(len, 0), right_max(len, 0);

//         left_max[0] = height[0];
//         right_max[len - 1] = height[len - 1];

//         for (int i = 1; i < len; ++ i) 
//             left_max[i] = max(height[i], left_max[i - 1]);

//         for (int i = len - 2; i >= 0; -- i) 
//             right_max[i] = max(height[i], right_max[i + 1]);


//         for (int i = 1; i < len - 1; ++ i) 
//             res += max(min(left_max[i - 1], right_max[i + 1]) - height[i], 0); 

//         return res;
//     }
// };
// /* ��ӡ�������
//             // cout << "i = " << i << " , left_max[i - 1] = " << left_max[i - 1] << " , right_max[i + 1] = " << right_max[i + 1] << endl;
// */


// ����ջ
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, len = height.size();
        if (len <= 1) return 0;
        stack<int> aux; //����ջ����������

        for (int i = 0; i < len; ++i) {

            while (!aux.empty() && height[i] > height[aux.top()]) {
                int top = aux.top();
                aux.pop();

                if (aux.empty()) break;
                int left = aux.top();

                int trap_width = i - left + 1 - 2; //[i,left]����i-left+1�����ӣ���ȥ���ұ߽�
                int trap_height = min(height[left], height[i]) - height[top];
                res += trap_width * trap_height;
            }
            aux.push(i);
        }

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}