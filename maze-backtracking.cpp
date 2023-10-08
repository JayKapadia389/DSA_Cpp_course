#include <iostream>

using namespace std ;

int ans[5][5] = {0};
int curr[2] = {0 , 0};
int de[3] = {0};
int entry[2] = {0};

void isDE(int curr[2] , int que[5][5]){

    int c = 0;

    if((curr[1] + 1) < 5 && que[curr[0]][curr[1]+1] == 1){
        c++;
         if(!ans[curr[0]][curr[1]+1]){
        de[0] = curr[0] ;
        de[1] = curr[1] + 1;
         }
         else{
            entry[0] = curr[0] ;
            entry[1] = curr[1] + 1;
         }
    }
    if((curr[0] + 1) && que[curr[0] + 1][curr[1]] == 1){

        c++;
        if(!ans[curr[0] + 1][curr[1]]){
        de[0] = curr[0] + 1 ;
        de[1] = curr[1];
        }
        else{
            entry[0] = curr[0] +1;
            entry[1] = curr[1] ;
         }
    }
    if((curr[1] - 1)>=0 && que[curr[0]][curr[1] - 1] == 1){

        c++;
        if(!ans[curr[0]][curr[1] - 1]){
            de[0] = curr[0];
            de[1] = curr[1] - 1;
        }   
        else{
            entry[0] = curr[0] ;
            entry[1] = curr[1] - 1;
         }
    }
    if((curr[0] - 1)>=0 && que[curr[0] - 1][curr[1]] == 1){

        c++;
        if(!ans[curr[0] - 1][curr[1]]){
        de[0] = curr[0] - 1 ;
        de[1] = curr[1];
        }
        else{
            entry[0] = curr[0] -1 ;
            entry[1] = curr[1] ;
         }
    }

    de[2] = (c == 1)? 1 : 0;

    return ; 
}

void maze(int que[5][5]){

    while(curr[0] != 4 || curr[1] != 4){

        if(curr[0] == 0 && curr[1] == 0){
            if(que[curr[0]+1][curr[1]]){
                ans[curr[0]+1][curr[1]] = 1;
                curr[0] = curr[0]+1 ;
                curr[1] = curr[1];

            }
            else{
                ans[curr[0]][curr[1]+1] = 1;
                curr[0] = curr[0] ;
                curr[1] = curr[1]+1;

            }
        }
        else{

            isDE(curr,que);
            
            if(de[2]){
                que[curr[0]][curr[1]] = 0;
                ans[curr[0]][curr[1]] = 0;
                curr[0]=entry[0];
                curr[1]=entry[1];

            }
            else{

                ans[de[0]][de[1]] = 1;
                curr[0]=de[0];
                curr[1]=de[1];

                
            }
        }

    }

    return;

}

int main(){

    int que[5][5] = {{1,1,1,1,0},{0,1,0,1,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,1,1,1}};

    maze(que);

    for(int i =0 ;i<5 ;i++){

        for(int j =0 ;j<5 ;j++){
            cout << ans[i][j] << " " ;
        }

        cout << endl;
    }
}