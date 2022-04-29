#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//未通过
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int len = intervals.size();
//         vector<vector<int>> res;
//         sort(intervals.begin(), intervals.end());
//         bool flag = false;
//         bool flag1 = false;

//         int begin_intervals = intervals[0][0], end_intervals = intervals[0][1];
//         for (int i = 0; i < len - 1; ) {
//             if (intervals[i][1] >= intervals[i + 1][0]){
//                 i ++;
//                 if ( i == len - 2)
//                     flag = true;
//             }
//             else {
//                 flag1 = true;
//                 end_intervals = intervals[i][1];
//                 res.push_back({begin_intervals, end_intervals});
//                 begin_intervals = intervals[i + 1][0];
//                 i ++;

//             }
//         }

//         if (!flag1){
//             res.push_back({intervals[0][0], intervals[len - 1][1]});
//             return res;
//         }

//         if (!flag)
//             res.push_back({intervals[len - 1][0], intervals[len - 1][1]});
//         return res;
//     }
// };

//参考官方思路
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();

        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);
        for (int i = 1; i < len; ++i) {

            if (intervals[i][0] > merged.back()[1])
                merged.push_back(intervals[i]);

            else // intervals[i][0] <= merged.back()[1]
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }

        return merged;
    }
};

int main() {

	system("pause");
	return 0;
}