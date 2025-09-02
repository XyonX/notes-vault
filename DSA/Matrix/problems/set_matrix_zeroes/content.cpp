class Solution {
public:

void setRowZero(vector<vector<int>>& matrix,int row){
    for(int i=0;i<matrix[0].size();i++){
        matrix[row][i]=0;
    }
}

void setColZero(vector<vector<int>>& matrix,int col){
    for(int i=0;i<matrix.size();i++){
        matrix[i][col]=0;
    }
}
    void setZeroes(vector<vector<int>>& matrix) {

         int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false, firstCol = false;

        // Check if first row has zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Check if first column has zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }


        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
                }

            }
        }

        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                setRowZero(matrix,i);
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                setColZero(matrix,i);
            }
        }

        if(firstRow){
            setRowZero(matrix,0);
        }
        if(firstCol){
            setColZero(matrix,0);
        }
        
    }
};