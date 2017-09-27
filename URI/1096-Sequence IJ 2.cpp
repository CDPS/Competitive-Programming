#include <bits/stdc++.h>

using namespace std;

int main(){

    int j=1;
    int k=7;
    for(int i=0;i<=14;i++){

        if(i%3==0 && i!=0){
            k+=2;
            j+=2;
        }


        printf("I=%d J=%d\n",j, k-(i%3));
    }

    return 0;
}
