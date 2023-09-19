#include <bits/stdc++.h>

using namespace std;

int digitFrom10(int n){
    int pow = 100;
    int res = 0;
    while(pow <= n){
        res++;
        pow*=10;
    }
    return res;
}

int getOnes(int digits){
    int res = 0;
    while(digits--){
        res*=10;
        res+= 1;
    }
    return res;
}

int digitsFromRepetive(int n){

    int digits = log10(n) + 1;
    int res = (digits - 2) * 9;

    int repetitiveDigit = getOnes(digits);

    int acc = repetitiveDigit;
    while(acc <= n){
        res++;
        acc+=repetitiveDigit;

    }
    return res;
}

int main(){

    int n;

    cin >> n;

    int res = 0;

    if(n<=10){
        res = (n==10)? n : n+1;
    }else{
        res= 10 + digitFrom10(n) + digitsFromRepetive(n);
    }

    cout << res << "\n";
    return 0;
}
