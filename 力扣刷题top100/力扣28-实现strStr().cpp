#include<iostream>


using namespace std;

//没通过
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if (needle == "") return 0;
//         int index = 0;
//         int i = 0;
//         int last_i = 0;
//         for ( ; i < haystack.size(); ++ i) {
//             cout << i << index << endl;

//             if (index == needle.size()) break;
//             if (index < needle.size() && haystack[i] == needle[index]) {
//                 if (index == 0) last_i = i;
//                 ++ index;

//             }

//             else {
//                 if (index != 0) i = last_i + 1;
//                 index = 0;

//             }
//         }
//         cout << index << endl;
//         if (index == needle.size())
//             return i - index ;
//         return -1;
//     }
// };

//暴力法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int index = 0;

        for (int i = 0; i < haystack.size(); ++i) {
            int j = 0;
            for (; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == needle.size())
                return i;
        }

        return -1;
    }
};

int main() {

	system("pause");
	return 0;
}