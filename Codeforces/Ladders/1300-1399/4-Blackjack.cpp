#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    if(n<=10||n>21){
        printf("0\n");
    }
    else if( (n>=11 && n<=19) || n==21 ){
        printf("4\n");
    }else{
        printf("15");
    }
    return 0;
}
