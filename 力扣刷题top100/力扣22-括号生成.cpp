#include<iostream>


using namespace std;

// //暴力解法
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         string curent;
//         __generateParenthesis(curent, n, res);
//         return res;
//     }
// private:

//     //判断给定字符串中括号是否有效
//     bool isValid(const string& current) {
//         int balance = 0;
//         for (char ch : current) {
//             if (ch == '(')
//                 ++ balance;
//             else if(ch == ')')
//                 -- balance;

//             if (balance < 0) 
//                 return false;
//         }
//         return balance == 0;
//     }

//     //生成count对有效括号
//     void __generateParenthesis(string& curent, int count, vector<string>& res) {
//         if (2 * count == curent.size()) {
//             if (isValid(curent)) 
//                 res.push_back(curent);
//             return ;
//         } 

//         curent += "(";
//         __generateParenthesis(curent, count, res);
//         curent.pop_back();
//         curent += ")";
//         __generateParenthesis(curent, count, res);
//         curent.pop_back();


//         return ;

//     }
// };

//上边每次字符串都判断括号是否有效，我们可以用两个变量代表括号的数量，然后使每次添加的括号有效
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curent;
        __generateParenthesis(res, curent, n, 0, 0);
        return res;
    }
private:

    //生成count对有效括号
    void __generateParenthesis(vector<string>& res, const string& current, int count, int open, int close) {
        if (2 * count == current.size()) {

            res.push_back(current);
            return;
        }
        if (open < count) {
            string add = "(";
            __generateParenthesis(res, current + add, count, open + 1, close);
        }
        if (close < open) {
            string add = ")";
            __generateParenthesis(res, current + add, count, open, close + 1);
        }

        return;

    }
};

int main() {

	system("pause");
	return 0;
}