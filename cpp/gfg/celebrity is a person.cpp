class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        for(int i = 0; i < mat.size(); i++) {
            int count = 0;
            for(int j = 0; j < mat.size(); j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            if(count == 0) {
                for(int k = 0; k < mat.size(); k++) {
                    if(k != i && mat[k][i] == 0) {
                        return -1;
                    }
                }
                return i;
            }
        }
    }
};