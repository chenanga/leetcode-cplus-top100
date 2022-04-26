#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //两行和一行时候的情况可能需要特殊考虑
//         int n = s.size();
//         if(n <= 2 || n <= numRows || numRows == 1) return s;

//         string res = "";
//         vector<vector<char>> memo(numRows, vector<char>(n, '0'));
//         int index = 0;
//         for(int i = 0; i < n && index < n; i ++){ //列
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


// //避免赋值造成的耗时，可以把对应位置放上索引
// //memo使用int型，初始化为-1
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //两行和一行时候的情况可能需要特殊考虑
//         int n = s.size();
//         if(n <= 2 || n <= numRows || numRows == 1) return s;

//         string res = "";
//         vector<vector<int>> memo(numRows, vector<int>(n, -1));
//         int index = 0;
//         for(int i = 0; i < n && index < n; i ++){ //列
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


// //循环字符串长度次数，根据当前位置和numrows
// //字符串先向下 numRows 位置，然后像右上 numRows-2 位置，一个周期为 2 * numRows - 2, 占用的列数为 1 + numRows - 2.
// // 总共的列数为 (len / (周期) + 1) * 一个周期的列数
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         //两行和一行时候的情况可能需要特殊考虑
//         int n = s.size();
//         if (n <= 2 || n <= numRows || numRows == 1) return s;

//         int strT = 2 * numRows - 2;
//         int columnOfStr = (n / strT + 1) * (1 + numRows - 2);

//         string res = "";
//         vector<vector<int>> memo (numRows, vector<int>(columnOfStr, -1));
//         int index = 0;
//         for (int index = 0, x = 0, y = 0; index < n; index ++) { //列

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
//这题应该有个数学方法

//k神解法
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1) return s;
//         vector<string> rows(numRows);
//         // 行转向标志，极妙
//         int flag = 1;  
//         // 行下标索引
//         int idxRows = 0;   
//         for (int i = 0; i < s.size(); i++) {
//             rows[idxRows].push_back(s[i]);
//             // 更新行下标
//             idxRows += flag;  
//             if (idxRows == numRows - 1 || idxRows == 0) {
//                 // 转向，上——>下 | 下——>上
//                 flag = -flag;
//             }
//         }
//         string res;
//         for (auto row : rows) {
//             // 拿到答案
//             res += row;
//         }
//         return res;
//     }
// };

//参考k神
class Solution {
public:
    string convert(string s, int numRows) {
        //两行和一行时候的情况可能需要特殊考虑
        int n = s.size();
        if (n <= 2 || n <= numRows || numRows == 1) return s;

        int strT = 2 * numRows - 2;
        int columnOfStr = (n / strT + 1) * (1 + numRows - 2);

        string res = "";
        vector<string> memo(numRows);
        int index = 0;
        for (int index = 0, x = 0, y = 0; index < n; index++) { //列

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