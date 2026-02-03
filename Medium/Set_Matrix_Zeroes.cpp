class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        for (int r = 0; r < matrix.size(); ++r){
            if (matrix[r][0]==0){
                row0=true;
                break;
            }
        }
        for (int c = 0; c < matrix[0].size(); ++c){
            if (matrix[0][c]==0){
                col0=true;
                break;
            }
        }
        //set borders
        for (int r = 1; r < matrix.size(); ++r){
            for (int c = 1; c < matrix[0].size(); ++c){
                if (matrix[r][c]==0){
                    matrix[0][c]=0;
                    matrix[r][0]=0;
                }
            }
        }

        for (int r = 1; r < matrix.size(); ++r){
            if (matrix[r][0]==0){
                for (int c = 1; c < matrix[0].size(); ++c){
                    matrix[r][c]=0;
                }
            }
        }

        for (int c = 1; c < matrix[0].size(); ++c){
            if (matrix[0][c]==0){
                for (int r = 1; r < matrix.size(); ++r){
                    matrix[r][c]=0;
                }
            }
        }
        if (col0) {
            for (int c = 0; c < matrix[0].size(); ++c) matrix[0][c] = 0;
        }
        if (row0) {
            for (int r = 0; r < matrix.size(); ++r) matrix[r][0] = 0;
        }
    }
};