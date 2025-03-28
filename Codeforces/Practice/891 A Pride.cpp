#include <bits/stdc++.h>

using namespace std;

int oo = 1e9;
int a[2000];

int main(){

    int n ,m = 0;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i], m+= a[i]!=1;

    if(m==0){
        cout << 0 << "\n";
        return 0;
    }

    int mini = oo;
    for(int i=0;i<n;i++){
        int gcd = a[i];
        for(int j=i+1;j<n;j++){
            if(__gcd(gcd, a[j]) == 1 && j-i < mini)
                mini = j-i;
            gcd = __gcd(gcd, a[j]);
        }
    }
    cout << (mini == oo? -1 : m + (mini-1) ) << "\n";

    return 0;
}
