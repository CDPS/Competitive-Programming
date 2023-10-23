#include <bits/stdc++.h>

using namespace std;

char g[8][8];

int findMinimunA(){
    int mini = 20;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(g[i][j]=='W'){
                int result = 0;
                for(int k=i-1;k>=0;k--){
                    if(g[k][j]!='.'){
                        result = 20;
                        break;
                    }
                    result++;
                }
                mini = min(result,mini);
            }
        }
    }
    return mini;
}

int findMinimunB(){
    int mini = 20;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(g[i][j]=='B'){
                int result = 0;
                for(int k=i+1; k<8;k++){
                    if(g[k][j]!='.'){
                        result = 20;
                        break;
                    }
                    result++;
                }
                mini = min(result,mini);
            }
        }
    }

    return mini;
}

int main(){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin >> g[i][j];
    int a = findMinimunA();
    int b = findMinimunB();
    cout << (  (a-1<b)? "A" : "B" ) << "\n";
    return 0;
}
