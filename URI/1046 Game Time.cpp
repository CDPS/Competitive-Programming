#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b;

    cin >> a >> b;

    int res =0;
    if(a==b){
        res = 24;
    }
    else if(b<a){
        res=24 - a +b;
    }
    else{
        res = b-a;
    }

    printf("O JOGO DUROU %d HORA(S)\n",res);
    return 0;
}
