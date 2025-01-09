class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> cmatrix;
        int n = matrix.size();
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> row;
            for(int j = 0; j < matrix[i].size(); j++) {
                row.push_back(matrix[i][j]);
            }
            cmatrix.push_back(row);
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = cmatrix[n - j - 1][i];
            }
        }
    }
};
