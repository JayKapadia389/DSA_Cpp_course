#include <set>
#include <string>

class Solution {
public:

    set<string> getSet(int i , int j , vector<vector<char>>& board){

        set<string> posValSet = {"1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9"} ;

        for(int k = 0 ; k < 9 ; k++ ){
            posValSet.erase(board[i][k]);
        }

        for(int k = 0 ; k < 9 ; k++ ){
            posValSet.erase(board[k][j]);
        }

        int row ;
        int col ;

        if(i >= 0 && i <= 2){
            row = 0 ;
        }
        else if(i >= 3 && i <= 5){
            row = 3 ;
        }
        else{
            row = 6 ;
        }

        if(j >= 0 && j <= 2){
            col = 0 ;
        }
        else if(j >= 3 && j <= 5){
            col = 3 ;
        }
        else{
            col = 6 ;
        }

        for(int a = row ; a < row + 3 ; a++){
            for(int b = col ; b < col + 3 ; b++){
                posValSet.erase(board[a][b]);
            }
        }

        return posValSet;

    }

    vector<int> nextPos(int i , int j , vector<vector<char>>& board){

        while(i != 9){
            while(j != 9){
                if(board[i][j] == "."){
                    return [i , j , 1];
                }
                j++;
            }
            i++ ;
            j =0 ;
        }

        return [0 , 0 ,0];
    }

    bool sudokuCore(int i , int j , vector<vector<char>>& board){
        
        set<string> posVal = getSet(i , j , board);

        vector<int> nextPosVec = nextPos(i , j , board);

        while(!posVal.empty()){

            board[i][j] = *(posVal.begin());
            posVal.erase(board[i][j]);

            if(nextPosVec[3]){
                if(sudokuCore(nextPosVec[1] , nextPosVec[2] ,board )){
                    return 1;
                }
            }
            else{
                return 1; 
            }
        }

        board[i][j] = ".";
        return false;

    }


    void solveSudoku(vector<vector<char>>& board) {

        bool flag = 0 ;
        
        for(int i = 0 ; i < 9 ;i++){
            for(int j=0  ; j<9 ;j++){
                if(board[i][j] == "."){
                    sudokuCore( i , j , board);

                    flag =1;
                    break ;
                }
            }
            if(flag){
                break;
            }
        }

        return ;
    }
};