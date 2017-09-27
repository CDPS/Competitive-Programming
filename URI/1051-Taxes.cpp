#include   <bits/stdc++.h>

using namespace std;

int main(){

    double n;

    cin >> n;

    if(n<=2000.00){
        printf("Isento\n");
    }
    else if( n<=3000.00){
        printf("R$ %2.lf\n",n * 0.08);
    }else if( n <= 4500.00){
        printf("R$ %.2lf\n", n* 0.18);
    }else{
        printf("R$ %.2lf\n", n * 0.28);
    }
    return 0;
}
