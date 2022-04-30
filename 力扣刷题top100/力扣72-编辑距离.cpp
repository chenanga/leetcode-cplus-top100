#include<iostream>
#include<vector>

using namespace std;

//��̬�滮
/*
��word1[i-1]==word2[j-1]
    dp[i][j] = dp[i-1][j-1]
��word1[i-1]!=word2[j-1],
    dp[i][j] = dp[i-1][j] + 1   ����һ���ַ�
    dp[i][j] = dp[i][j-1] + 1   ɾ��һ���ַ�
    dp[i][j] = dp[i-1][j-1] + 1 �滻һ���ַ�
*/
class Solution {
public:
    int minDistance(string word1, string word2) {

        int len_word1 = word1.size(), len_word2 = word2.size();

        //����dp���飬dp[i][j]����word1��ǰi�����ʺ�word2��ǰj�����ʵı༭���룬��һ���Ǽ����˿��ַ���
        vector<vector<int>> dp(len_word1 + 1, vector<int>(len_word2 + 1, -1));

        //��ʼ��dp����
        for (int i = 0; i <= len_word1; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= len_word2; ++i)
            dp[0][i] = i;

        //��̬�滮
        for (int i = 1; i <= len_word1; ++i) {
            for (int j = 1; j <= len_word2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else //word1[i - 1]!=word2[j - 1]
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        return dp[len_word1][len_word2];

    }
};

int main() {

	system("pause");
	return 0;
}