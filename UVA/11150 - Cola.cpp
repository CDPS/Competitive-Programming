#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,res=0;

    while(cin >> n){
        res=n; n++;
        while(n>=3){
            res+= (n/3);
            n= (n/3)+ (n%3);
        }
        cout <<  res << "\n";
    }
    return 0;
}
