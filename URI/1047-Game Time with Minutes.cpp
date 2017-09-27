#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,c,d;

    cin >> a>>c >> b>> d;

    int mt =0;
    int h=0;

    if(d< c){
        mt = 60 - c +d;
        h--;
    }else{
        mt = d-c;
    }

    if(mt >= 60){
        h++;
        mt-=60;
    }

    if(a==b){
        h=24;
    }
    else if ( a>b){
        h+= 24-a+b;
    }else{
        h += b-a;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h,mt);

    return 0;
}
