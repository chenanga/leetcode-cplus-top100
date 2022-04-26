#include<iostream>


using namespace std;

// class Solution {
// public:
//     string intToRoman(int num) {

//         string res = "";
//         unordered_map<int,char> mp = {
//             {1, 'I'}, 
//             {5, 'V'}, 
//             {10, 'X'}, 
//             {50, 'L'}, 
//             {100, 'C'}, 
//             {500, 'D'}, 
//             {1000, 'M'}
//         };

//         //处理千位
//         int temp = num / 1000;
//         if (temp != 0) {
//             for (int i = 0; i < temp; ++ i) 
//                 res.push_back(mp[1000]);    
//         }

//         //处理百位
//         temp = num % 1000 / 100;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "CM";
//             }
//             else if (temp == 4) {
//                 res += "CD";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back(mp[500]);
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back(mp[100]);
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back(mp[100]);
//                 }
//             }

//         }

//         //处理十位
//         temp = num % 100 / 10;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "XC";
//             }
//             else if (temp == 4) {
//                 res += "XL";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back(mp[50]);
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back(mp[10]);
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back(mp[10]);
//                 }
//             }
//         }

//         //处理个位
//         temp = num % 10;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "IX";
//             }
//             else if (temp == 4) {
//                 res += "IV";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back(mp[5]);
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back(mp[1]);
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back(mp[1]);
//                 }
//             }
//         }
//         return res;        
//     }
// };

// //不使用map，直接赋值
// class Solution {
// public:
//     string intToRoman(int num) {

//         string res = "";
//         res.push_back('A');
//         res += "A";

//         //处理千位
//         int temp = num / 1000;
//         if (temp != 0) {
//             for (int i = 0; i < temp; ++ i) 
//                 res.push_back('M');    
//         }

//         //处理百位
//         temp = num % 1000 / 100;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "CM";
//             }
//             else if (temp == 4) {
//                 res += "CD";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back('D');
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back('C');
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back('C');
//                 }
//             }

//         }

//         //处理十位
//         temp = num % 100 / 10;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "XC";
//             }
//             else if (temp == 4) {
//                 res += "XL";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back('L');
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back('X');
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back('X');
//                 }
//             }
//         }

//         //处理个位
//         temp = num % 10;
//         if (temp != 0) {
//             if ( temp == 9) {
//                 res += "IX";
//             }
//             else if (temp == 4) {
//                 res += "IV";
//             }
//             else { //temp <= 3 || (temp >= 5 && temp != 9)
//                 if (temp >= 5) {
//                     res.push_back('V');
//                     for (int i = 0; i < temp - 5; ++ i) 
//                         res.push_back('I');
//                 }
//                 else {
//                     for (int i = 0; i < temp; ++ i) 
//                         res.push_back('I');
//                 }
//             }
//         }
//         return res;        
//     }
// };

// //官方解答1
// const pair<int, string> valueSymbols[] = {
//     {1000, "M"},
//     {900,  "CM"},
//     {500,  "D"},
//     {400,  "CD"},
//     {100,  "C"},
//     {90,   "XC"},
//     {50,   "L"},
//     {40,   "XL"},
//     {10,   "X"},
//     {9,    "IX"},
//     {5,    "V"},
//     {4,    "IV"},
//     {1,    "I"},
// };

// class Solution {
// public:
//     string intToRoman(int num) {
//         string roman;
//         for (const auto &[value, symbol] : valueSymbols) {
//             while (num >= value) {
//                 num -= value;
//                 roman += symbol;
//             }
//             if (num == 0) {
//                 break;
//             }
//         }
//         return roman;
//     }
// };


// //官方解答2
const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

class Solution {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};



int main() {

	system("pause");
	return 0;
}