#include<iostream>
#include<vector>

using namespace std;

// //˼·�����ˣ����ǿ��ǵĲ���̫̫ȫ��  
//188 / 265
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int len = nums.size();
//         if (len == 1) return ;
//         int i = len - 1;
//         //�������λ��ʼ��ǰ�����Խ�����������������ԭ�ȵģ���ֹͣ
//         for ( ; i >= 1; -- i) {

//             if (nums[i - 1] < nums[i]) {
//                 //�Ѻ�������
//                 vector<int>::iterator iter = nums.begin();

//                 for (int j = 0; j < i; ++ j)
//                     iter ++;
//                 swap(nums[i - 1], nums[i]);
//                 sort(iter, nums.end());

//                 break;
//             } 
//             swap(nums[i - 1], nums[i]);


//         }
//         if (i == 0) {
//             //��Ҫ��ת
//             sort(nums.begin(), nums.end());
//         }
//         return;
//     }
// };


//���ٷ�����Ľ��
/*
������ [4,5,2,6,3,1] Ϊ����

�������ҵ��ķ���������һ�ԡ���С�����롸�ϴ����������Ϊ 2 �� 3�����㡸��С�����������ң������ϴ�����������С��

��������ɽ��������б�Ϊ [4,5,3,6,2,1]����ʱ���ǿ������š���С�����ұߵ����У����б�Ϊ [4,5,3,1,2,6]��

����أ����������������㷨�����ڳ���Ϊ n ������ a��

���ȴӺ���ǰ���ҵ�һ��˳��� (i,i+1)������ a[i]<a[i+1]����������С������Ϊ a[i]����ʱ [i+1,n) ��Ȼ���½����С�

����ҵ���˳��ԣ���ô������ [i+1,n)�дӺ���ǰ���ҵ�һ��Ԫ�� j ���� a[i]<a[j]���������ϴ�������Ϊ a[j]��

���� a[i] �� a[j]����ʱ����֤������ [i+1,n) ��Ϊ�������ǿ���ֱ��ʹ��˫ָ�뷴ת���� [i+1,n)ʹ���Ϊ���򣬶�����Ը������������

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return;
        int i = len - 1;
        //�������λ��ʼ��ǰ�����Ե�ǰλ������һλ����ֹͣ
        for (; i >= 1; --i) {

            if (nums[i - 1] < nums[i]) {
                //�Ӻ���ǰ�ҵ�һ������nums[i-1], ����
                for (int j = len - 1; j >= i; --j) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        break;
                    }
                }

                //����һ��Ϊ�������У�����ֱ�ӷ�ת
                reverse(nums.begin() + i, nums.end());
                break;
            }

        }
        if (i == 0)
            reverse(nums.begin(), nums.end());

        return;
    }
};
// c++ stl��ʵ��         next_permutation(nums.begin(),nums.end()); // STL���ܺ���Ŀ����һ��

// //�ٷ����
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 2;
//         while (i >= 0 && nums[i] >= nums[i + 1]) {
//             i--;
//         }
//         if (i >= 0) {
//             int j = nums.size() - 1;
//             while (j >= 0 && nums[i] >= nums[j]) {
//                 j--;
//             }
//             swap(nums[i], nums[j]);
//         }
//         reverse(nums.begin() + i + 1, nums.end());
//     }
// };



int main() {

	system("pause");
	return 0;
}