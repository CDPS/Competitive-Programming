#include <bits/stdc++.h>

using namespace std;


string digits [10] = {"zero","one","two","three","four","five", "six","seven","eight","nine"};
string tens   [10] = {"ten","eleven","twelve","thirteen","fourteen", "fifteen","sixteen","seventeen","eighteen","nineteen"};
string tenpow [8] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main(){

    int n;
    cin >> n;

    if(n<=9){
        cout << digits[n] << "\n";
    }
    else if(n>=10 && n <=19){
        cout << tens[n-10] << "\n";
    }
    else if(n%10==0){
        cout << tenpow[ (n-20)/10 ] << "\n";
    }else{
        int digit1 = n/10;
        int digit2 = n%10;

        cout  << tenpow[ digit1-2 ] << "-" << digits [digit2] << "\n";
    }
    return 0;
}

