#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// //��������ö��ÿ�����������������������
// //87 / 96 ��ͨ����������
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int len = heights.size();
//         int res = 0;
//         for (int i = 0; i < len; ++ i) {

//             int left = i - 1, right = i + 1;

//             while (left >= 0 && heights[left] >= heights[i])
//                 -- left;

//             while (right < len && heights[right] >= heights[i])
//                 ++ right;

//             int width =  right - left - 1;
//             res = max(res, width * heights[i]);
//         }
//         return res;

//     }
// };

// //ʹ�õ���ջ�Ż����������
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int len = heights.size();

//         stack<int> stk;
//         vector<int> left(len, 0), right(len, 0);

//         //�ֱ�ȷ��ÿ�����ӵ���߽���ұ߽�
//         for (int i = 0; i < len; ++ i) {
//             while (!stk.empty() && heights[stk.top()] >= heights[i]) 
//                 stk.pop();
//             left[i] = (stk.empty() ? -1 : stk.top());
//             stk.push(i);
//         }

//         stk = stack<int>();
//         for (int i = len - 1; i >= 0; -- i) {
//             while (!stk.empty() && heights[stk.top()] >= heights[i]) 
//                 stk.pop();
//             right[i] = (stk.empty() ? len : stk.top());
//             stk.push(i);   
//         }

//         int res = 0;
//         for (int i = 0; i < len; ++ i) 
//             res = max(res, (right[i] - left[i] - 1) * heights[i]);

//         return res;

//     }
// };

//ʹ�õ���ջ�Ż�,һ�����
//��Ԫ�س�ջʱ��˵����ջλ�õĸ߶ȴ��ڵ��ڵ�ǰλ�õĸ߶ȣ�Ҳ�ǵ�һ��С�ڳ�ջλ�õ�Ԫ�أ�����right[c��] = ��ǰ
//��󻹻��в���Ԫ��û�г�ջ����ЩԪ�ض����ұ߽�Ϊlen��
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();

        stack<int> stk;
        vector<int> left(len, 0), right(len, len);

        //�ֱ�ȷ��ÿ�����ӵ���߽���ұ߽�
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < len; ++i)
            res = max(res, (right[i] - left[i] - 1) * heights[i]);

        return res;

    }
};

int main() {

	system("pause");
	return 0;
}