#include <bits/stdc++.h>

using namespace std;

int main(){

    double s;
    cin >> s;

    double p;
    int r=0;
    if(s <= 400.00){
        p=1.15;
        r=15;
    }
    else if(s<=800.00){
        p=1.12;
        r=12;
    }
    else if(s<=1200.00){
        p=1.10;
        r=10;
    }
    else if(s<=2000.00){
        p=1.07;
        r=7;
    }else{
        p=1.04;
        r=4;
    }

    double in= s*p;

    printf("Novo salario: %.2lf\n",s*p );
    printf("Reajuste ganho: %.2lf\n",s*p-s);
    printf("Em percentual: %d %%\n",r);
    return 0;
}
