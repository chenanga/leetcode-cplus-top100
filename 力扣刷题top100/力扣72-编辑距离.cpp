#include<iostream>
#include<vector>

using namespace std;

//动态规划
/*
当word1[i-1]==word2[j-1]
    dp[i][j] = dp[i-1][j-1]
当word1[i-1]!=word2[j-1],
    dp[i][j] = dp[i-1][j] + 1   插入一个字符
    dp[i][j] = dp[i][j-1] + 1   删除一个字符
    dp[i][j] = dp[i-1][j-1] + 1 替换一个字符
*/
class Solution {
public:
    int minDistance(string word1, string word2) {

        int len_word1 = word1.size(), len_word2 = word2.size();

        //定义dp数组，dp[i][j]代表word1的前i个单词和word2的前j个单词的编辑距离，多一行是加入了空字符串
        vector<vector<int>> dp(len_word1 + 1, vector<int>(len_word2 + 1, -1));

        //初始化dp数组
        for (int i = 0; i <= len_word1; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= len_word2; ++i)
            dp[0][i] = i;

        //动态规划
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