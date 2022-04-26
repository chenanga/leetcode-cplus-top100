#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //���к�һ��ʱ������������Ҫ���⿼��
//         int n = s.size();
//         if(n <= 2 || n <= numRows || numRows == 1) return s;

//         string res = "";
//         vector<vector<char>> memo(numRows, vector<char>(n, '0'));
//         int index = 0;
//         for(int i = 0; i < n && index < n; i ++){ //��
//             if( i % (numRows-1) == 0){
//                 for(int j = 0; j < numRows && index < n; j ++){

//                     memo[j][i] = s[index];
//                     index++;

//                 }
//             }
//             else{
//                 memo[numRows - 1 - i % (numRows-1)][i] = s[index];
//                 index++;    

//             }
//         }
//         for(int i = 0; i < numRows; i ++){
//             for(int j = 0; j < n; j ++){
//                 if(memo[i][j] != '0')
//                     res.push_back(memo[i][j]) ;   

//             }
//         }
//         return res;
//     }
// };


// //���⸳ֵ��ɵĺ�ʱ�����԰Ѷ�Ӧλ�÷�������
// //memoʹ��int�ͣ���ʼ��Ϊ-1
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //���к�һ��ʱ������������Ҫ���⿼��
//         int n = s.size();
//         if(n <= 2 || n <= numRows || numRows == 1) return s;

//         string res = "";
//         vector<vector<int>> memo(numRows, vector<int>(n, -1));
//         int index = 0;
//         for(int i = 0; i < n && index < n; i ++){ //��
//             if( i % (numRows-1) == 0){
//                 for(int j = 0; j < numRows && index < n; j ++){

//                     memo[j][i] = index;
//                     index++;

//                 }
//             }
//             else{
//                 memo[numRows - 1 - i % (numRows-1)][i] = index;
//                 index++;    

//             }
//         }
//         for(int i = 0; i < numRows; i ++){
//             for(int j = 0; j < n; j ++){
//                 if(memo[i][j] != -1)
//                     res.push_back(s[memo[i][j]]) ;   

//             }
//         }
//         return res;
//     }
// };


// //ѭ���ַ������ȴ��������ݵ�ǰλ�ú�numrows
// //�ַ��������� numRows λ�ã�Ȼ�������� numRows-2 λ�ã�һ������Ϊ 2 * numRows - 2, ռ�õ�����Ϊ 1 + numRows - 2.
// // �ܹ�������Ϊ (len / (����) + 1) * һ�����ڵ�����
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //���к�һ��ʱ������������Ҫ���⿼��
//         int n = s.size();
//         if (n <= 2 || n <= numRows || numRows == 1) return s;

//         int strT = 2 * numRows - 2;
//         int columnOfStr = (n / strT + 1) * (1 + numRows - 2);

//         string res = "";
//         vector<vector<int>> memo (numRows, vector<int>(columnOfStr, -1));
//         int index = 0;
//         for (int index = 0, x = 0, y = 0; index < n; index ++) { //��

//             memo[x][y] = index;

//             if (index % (2 * numRows - 2) < numRows - 1) 
//                 x ++;

//             else {
//                 x --;
//                 y ++;  
//             }    
//         }

//         for (int i = 0; i < numRows; i ++) 
//             for (int j = 0; j < columnOfStr; j ++) {
//                 if (memo[i][j] != -1)
//                     res += s[memo[i][j]];   

//             }

//         return res;
//     }
// };
//����Ӧ���и���ѧ����

//k��ⷨ
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1) return s;
//         vector<string> rows(numRows);
//         // ��ת���־������
//         int flag = 1;  
//         // ���±�����
//         int idxRows = 0;   
//         for (int i = 0; i < s.size(); i++) {
//             rows[idxRows].push_back(s[i]);
//             // �������±�
//             idxRows += flag;  
//             if (idxRows == numRows - 1 || idxRows == 0) {
//                 // ת���ϡ���>�� | �¡���>��
//                 flag = -flag;
//             }
//         }
//         string res;
//         for (auto row : rows) {
//             // �õ���
//             res += row;
//         }
//         return res;
//     }
// };

//�ο�k��
class Solution {
public:
    string convert(string s, int numRows) {
        //���к�һ��ʱ������������Ҫ���⿼��
        int n = s.size();
        if (n <= 2 || n <= numRows || numRows == 1) return s;

        int strT = 2 * numRows - 2;
        int columnOfStr = (n / strT + 1) * (1 + numRows - 2);

        string res = "";
        vector<string> memo(numRows);
        int index = 0;
        for (int index = 0, x = 0, y = 0; index < n; index++) { //��

            memo[x].push_back(s[index]);

            if (index % (2 * numRows - 2) < numRows - 1)
                x++;

            else {
                x--;
                y++;
            }
        }

        for (int i = 0; i < numRows; i++)
            res += memo[i];

        return res;
    }
};


int main() {
    cout << "a + b = 1" << endl;

	system("pause");
	return 0;
}