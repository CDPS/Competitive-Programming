#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int acc = 0;
    for(int a=1; a <=n;a++){
        for(int b = a+1; b<=n;b++){
            int c = a ^ b ;
            if(c > b && c<=n && (a+b > c) && (a+c>b) && (b+c>a) ){
                acc++;
            }
        }
    }
    cout << acc << "\n";
    return 0;
}
