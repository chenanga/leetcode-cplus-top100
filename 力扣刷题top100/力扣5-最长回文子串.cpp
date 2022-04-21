#include<iostream>
#include<vector>
using namespace std;


// class Solution {
// public:
//     //必须为连续子串
//     //动态规划
//     string longestPalindrome(string s) {

//         int n = s.size();
//         if (n <2 ) return s;


//         // unordered_map<int,pair<int,int>> mp;
//         int count = 1;
//         int left=0,right=0;
//         //dp[i][j]表示字符串s[i...j]是否为回文串
//         vector<vector<bool>>dp(n, vector<bool>(n, false));

//         //初始化递归数组,单个字符是回文串
//         //初始化时候也需要考虑两两的字符串，
//         //如果i>j，也为false
//         for(int i = 0; i < n; i ++ ){
//             dp[i][i] = true;
//             if( i != n-1 && s[i] == s[i+1]){

//                 dp[i][i+1] = true;
//                 if(count < 2 && dp[i][i+1]){ //优化，初始化时候，可能有多个满足长度为2的
//                     count = 2;
//                     left = i;
//                     right = i+1;
//                 }

//             }
//         }

//         //dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
//         for(int i = n - 2; i >= 0 ; i --)
//             for(int j = i + 1; j < n; j ++){
//                 if(!dp[i][j]) {//如果不为0，则跳过
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

//中心扩展法
//假设给定每个字符串的中心位置，判断改字符串最长的回文串是多少
//由于长度有奇数有偶数，故中心位置可以为n(奇数长度的中心位置) + n-1(偶数长度的中心位置)  
class Solution {
public:

    string longestPalindrome(string s) {
        int count = 1;
        int n = s.size();
        int left = 0;
        if (n < 2) return s;
        for (int i = 0; i < n; i++) {
            // cout<<i<<"为中心,"<<endl;
            int maxlen = 0;
            int ret1 = judgeStrJishu(s, i);
            // cout<<"奇数 ret1 = "<<ret1<<endl;
            int ret2 = 0;
            if (i != n - 1) {
                //先判断中心的两个是不是相同
                if (s[i] == s[i + 1])
                    ret2 = judgeStrOuShu(s, i);
            }
            // cout<<"偶数 ret2 = "<<ret2<<endl;

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
    // 字符以mid为中心，向两边扩散
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

    // 字符以mid,mid+1为中心，向两边扩散
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

