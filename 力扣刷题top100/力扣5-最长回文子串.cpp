#include<iostream>
#include<vector>
using namespace std;


// class Solution {
// public:
//     //����Ϊ�����Ӵ�
//     //��̬�滮
//     string longestPalindrome(string s) {

//         int n = s.size();
//         if (n <2 ) return s;


//         // unordered_map<int,pair<int,int>> mp;
//         int count = 1;
//         int left=0,right=0;
//         //dp[i][j]��ʾ�ַ���s[i...j]�Ƿ�Ϊ���Ĵ�
//         vector<vector<bool>>dp(n, vector<bool>(n, false));

//         //��ʼ���ݹ�����,�����ַ��ǻ��Ĵ�
//         //��ʼ��ʱ��Ҳ��Ҫ�����������ַ�����
//         //���i>j��ҲΪfalse
//         for(int i = 0; i < n; i ++ ){
//             dp[i][i] = true;
//             if( i != n-1 && s[i] == s[i+1]){

//                 dp[i][i+1] = true;
//                 if(count < 2 && dp[i][i+1]){ //�Ż�����ʼ��ʱ�򣬿����ж�����㳤��Ϊ2��
//                     count = 2;
//                     left = i;
//                     right = i+1;
//                 }

//             }
//         }

//         //dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
//         for(int i = n - 2; i >= 0 ; i --)
//             for(int j = i + 1; j < n; j ++){
//                 if(!dp[i][j]) {//�����Ϊ0��������
//                     dp[i][j] = dp[i+1][j-1] && s[i] == s[j] ;

//                     if(dp[i][j] && count < j-i+1){
//                         // cout<<"i-j"<<i-j<<"i = "<<i<<" j = "<<j<<endl;
//                         count = j-i+1;
//                         left = i;
//                         right = j;
//                     }
//                 }
//             }


//         return s.substr(left, right - left + 1);
//     }
// };

//������չ��
//�������ÿ���ַ���������λ�ã��жϸ��ַ�����Ļ��Ĵ��Ƕ���
//���ڳ�����������ż����������λ�ÿ���Ϊn(�������ȵ�����λ��) + n-1(ż�����ȵ�����λ��)  
class Solution {
public:

    string longestPalindrome(string s) {
        int count = 1;
        int n = s.size();
        int left = 0;
        if (n < 2) return s;
        for (int i = 0; i < n; i++) {
            // cout<<i<<"Ϊ����,"<<endl;
            int maxlen = 0;
            int ret1 = judgeStrJishu(s, i);
            // cout<<"���� ret1 = "<<ret1<<endl;
            int ret2 = 0;
            if (i != n - 1) {
                //���ж����ĵ������ǲ�����ͬ
                if (s[i] == s[i + 1])
                    ret2 = judgeStrOuShu(s, i);
            }
            // cout<<"ż�� ret2 = "<<ret2<<endl;

            maxlen = max(ret1, ret2);
            if (maxlen > count) {
                count = maxlen;
                if (ret1 > ret2) {
                    left = i - ret1 / 2;
                }
                else {
                    left = i - ret2 / 2 + 1;
                }
            }

        }

        return s.substr(left, count);
    }
private:
    // �ַ���midΪ���ģ���������ɢ
    int judgeStrJishu(string& s, int mid) {
        int len = 1;
        int left = mid - 1;
        int right = mid + 1;
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right])
                len += 2;
            else
                break;

            left--;
            right++;
        }
        return len;
    }

    // �ַ���mid,mid+1Ϊ���ģ���������ɢ
    int judgeStrOuShu(string& s, int mid) {
        int len = 2;
        int left = mid - 1;
        int right = mid + 2;
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right])
                len += 2;

            else
                break;

            left--;
            right++;
        }
        return len;
    }

};

int main() {

	system("pause");
	return 0;
}

