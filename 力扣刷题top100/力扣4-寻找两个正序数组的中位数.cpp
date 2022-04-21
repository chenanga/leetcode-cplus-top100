#include<iostream>
#include<vector>

using namespace std;



//���ٷ����д������
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();

        int len = len1 + len2;
        int flag = len % 2; //flag: 0,������Ϊż������ҪѰ���м���������flag��1������Ѱ���м�һ����
        if (flag) {
            return getKLength(nums1, nums2, len / 2 + 1);
        }
        else {

            return (getKLength(nums1, nums2, len / 2) + getKLength(nums1, nums2, len / 2 + 1)) / 2.0;
        }


    }
private:
    //Ѱ���������������е�kС��Ԫ��
    int getKLength(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();

        int index1 = 0, index2 = 0;
        while (true) {
            //�ж�Խ�����
            if (index1 == len1) //����1��ͷ��
                return nums2[index2 + k - 1];
            if (index2 == len2)
                return nums1[index1 + k - 1];
            if (k == 1)
                return min(nums1[index1], nums2[index2]);

            int newindex1 = min(index1 + k / 2 - 1, len1 - 1);
            int newindex2 = min(index2 + k / 2 - 1, len2 - 1);

            int nums1Mid = nums1[newindex1];
            int nums2Mid = nums2[newindex2];

            if (nums1Mid >= nums2Mid) {
                //ɾ��nums2[0...index2]
                k -= (newindex2 - index2 + 1);
                index2 = newindex2 + 1;
            }
            else {
                k -= (newindex1 - index1 + 1);
                index1 = newindex1 + 1;
            }

        }
        return -1;
    }
};


int main() {

	system("pause");
	return 0;
}