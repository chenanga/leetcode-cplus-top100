#include<iostream>
#include<vector>

using namespace std;

//保证左括号的数量始终大于右括号，并且最终右括号的数量等于左括号，以及左括号开头
//动态规划的思想
/*
memo[i] 表示以下标 i 字符结尾的最长有效括号的长度
如果s[i] 为 ) 则有可能会有效字符，如果为(，则不可能
当s[i] == ),
如果s[i-1] == (，那么s[i-1]和s[i]组成一队，加上以i-2结尾的有效长度
如果s[i-1] == ),那么考虑在以s[i-1]为有效字符长度的前边是否是一个(，如果是，那么就是2 + 以s[i-1]的长度，以s[i-1]为有效字符长度的前边的前边的有效长度



还需要考虑越界问题
*/
class Solution {
public:
    int longestValidParentheses(string s) {

        int len = s.size();
        if (len <= 1) return 0;

        //memo[i] 表示以下标 i 字符结尾的最长有效括号的长度
        vector<int> memo(len, 0);
        int res = 0;
        for (int i = 1; i < len; ++i) {

            if (s[i] == ')') {

                if (s[i - 1] == '(') {
                    memo[i] = (i >= 2 ? memo[i - 2] : 0) + 2;
                }
                else if (i - memo[i - 1] - 1 >= 0 && s[i - memo[i - 1] - 1] == '(') {
                    memo[i] = memo[i - 1] + 2 + (i - memo[i - 1] - 2 >= 0 ? memo[i - memo[i - 1] - 2] : 0);
                }
            }
            res = max(res, memo[i]);

        }


        return res;
    }
};

int main() {

	system("pause");
	return 0;
}