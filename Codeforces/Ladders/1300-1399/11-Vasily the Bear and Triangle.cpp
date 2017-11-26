#include <bits/stdc++.h>

using namespace std;

int main(){

    int x,y,rx,ry;
    scanf("%d %d",&x,&y);
    if(x>0 && y>0){
        rx = x+y;
        ry = y+x;
    }
    else if(x>0 && y<0){
        rx= x-(y);
        ry = y-x;
    }
    else if(x<0 && y>0){
        rx = x-y;
        ry = y-x;
    }
    else if(x<0 && y<0){
        rx=  x+y;
        ry = y+x;
    }
    if(rx<0){
        printf("%d 0 0 %d\n",rx,ry);
    }else{
         printf("0 %d %d 0\n",rx,ry);
    }

    return 0;
}
