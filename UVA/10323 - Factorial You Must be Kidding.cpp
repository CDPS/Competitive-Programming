#include <bits/stdc++.h>

using namespace std;

unsigned long  fac[14];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    unsigned long r =1;

    for(unsigned long i=1;i<=13;i++)
        r = r*i,fac[i] =r;

    int n;
    while(cin >> n){

        if(n<0 && n%2){
            cout << "Overflow!\n";
        }
        else if(n<=7){
            cout << "Underflow!\n";
        }else if(n>=8 && n<=13){
            cout << fac[n] << "\n";
        }else{
            cout << "Overflow!\n";
        }
    }
    return 0;
}
