#include<iostream>
#include<vector>

using namespace std;

//��֤�����ŵ�����ʼ�մ��������ţ��������������ŵ��������������ţ��Լ������ſ�ͷ
//��̬�滮��˼��
/*
memo[i] ��ʾ���±� i �ַ���β�����Ч���ŵĳ���
���s[i] Ϊ ) ���п��ܻ���Ч�ַ������Ϊ(���򲻿���
��s[i] == ),
���s[i-1] == (����ôs[i-1]��s[i]���һ�ӣ�������i-2��β����Ч����
���s[i-1] == ),��ô��������s[i-1]Ϊ��Ч�ַ����ȵ�ǰ���Ƿ���һ��(������ǣ���ô����2 + ��s[i-1]�ĳ��ȣ���s[i-1]Ϊ��Ч�ַ����ȵ�ǰ�ߵ�ǰ�ߵ���Ч����



����Ҫ����Խ������
*/
class Solution {
public:
    int longestValidParentheses(string s) {

        int len = s.size();
        if (len <= 1) return 0;

        //memo[i] ��ʾ���±� i �ַ���β�����Ч���ŵĳ���
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