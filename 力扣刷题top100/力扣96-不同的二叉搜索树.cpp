#include<iostream>
#include<vector>

using namespace std;

//二叉搜索树
/*
G(n)代表n个整数组成的二叉搜索树的个数
f(i,n)代表以i为根节点，n个整数组成的种数
G(n) = f(1,n) + f(2,n) + ... + f(n,n)
f(i,n) = g(i-1) * g(n-i)
g(0) = g(1) = 1
g(2) = 2
G(n) = g(1-1) * g(n-1) + g(2-1) * g(n-2) + g(i-1) * g(n-i)
*/
class Solution {
public:
    int numTrees(int n) {

        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];

    }
};

int main() {

	system("pause");
	return 0;
}