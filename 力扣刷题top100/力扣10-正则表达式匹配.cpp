#include<iostream>
#include<vector>

using namespace std;

//û������
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         //
//         int index_s = 0;
//         int index_p = 0;
//         while (index_s < s.size() && index_p < p.size()) {

//             if (index_p < p.size() - 1 && p[index_p + 1] == '*') { 
//                 while (index_s < s.size() && (p[index_p] == '.' || p[index_p] == s[index_s])) {
//                     ++ index_s;    
//                 }
//                 index_p += 2;
//             }

//             else if (p[index_p] == '.' || s[index_s] == p[index_p]) {
//                 ++ index_s;
//                 ++ index_p;
//             }
//         }
//         // cout << "index_s" << index_s << endl;
//         // cout << "index_p" << index_p << endl;

//         if (index_s == s.size()) 
//             return true;
//         else 
//             return false;
//     }
// };

//��̬�滮
class Solution {
public:
    bool isMatch(string s, string p) {

        int len_s = s.size() + 1, len_p = p.size() + 1;

        //dp[i][j]��ʾ �ַ���p[0...i-1] �� s[0...j-1]�Ƿ�ƥ��
        vector<vector<bool>> dp(len_s, vector<bool>(len_p, false));

        //��ʼ��
        dp[0][0] = true;
        for (int j = 2; j < len_p; j++)
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];

        for (int i = 1; i < len_s; i++) {
            for (int j = 1; j < len_p; j++) {
                // cout << "i = " << i << ", j = " << j << endl;
                if (p[j - 1] == '*') {
                    //��p[j-2]��p[j-1]����0�Σ� ����һ��
                    if (dp[i][j - 2])
                        dp[i][j] = true;
                    else if (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                        dp[i][j] = true;

                }
                else { //p[j - 1] != '*'
                    if (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                        dp[i][j] = true;
                }
            }
        }
        return dp[len_s - 1][len_p - 1];
    }
};

int main() {

	system("pause");
	return 0;
}