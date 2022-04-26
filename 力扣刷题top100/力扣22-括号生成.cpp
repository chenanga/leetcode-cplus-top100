#include<iostream>


using namespace std;

// //�����ⷨ
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         string curent;
//         __generateParenthesis(curent, n, res);
//         return res;
//     }
// private:

//     //�жϸ����ַ����������Ƿ���Ч
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

//     //����count����Ч����
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

//�ϱ�ÿ���ַ������ж������Ƿ���Ч�����ǿ��������������������ŵ�������Ȼ��ʹÿ����ӵ�������Ч
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curent;
        __generateParenthesis(res, curent, n, 0, 0);
        return res;
    }
private:

    //����count����Ч����
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