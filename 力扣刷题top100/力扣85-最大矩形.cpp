#include<iostream>
#include<vector>

using namespace std;

//统计每个位置及其左边连续1的个数
//依次向上寻找，找到最大值
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> left(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            int count = 0;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    ++count;
                else
                    count = 0;
                left[i][j] = count;
            }
        }

        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    int min_left = left[i][j];
                    for (int k = i; k >= 0; --k) {
                        min_left = min(min_left, left[k][j]);
                        int height = i - k + 1;
                        res = max(res, height * min_left);
                    }
                }


            }
        }
        return res;

    }
};
/*
                cout << "i = " << i << ", j = " << j << " ,res = "<< height * min_left <<" left[i][j] = " << left[i][j] << endl;
*/

int main() {

	system("pause");
	return 0;
}