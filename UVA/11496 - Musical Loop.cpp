#include <bits/stdc++.h>

using namespace std;

int a[10001];

int main(){

    int n;
    while(cin >> n && n){

        for(int i=1;i<=n;i++)
            cin >> a[i];
        a[0] = a[n];
        a[n+1] = a[1];

        int pikes =  0;
        for(int i=1;i<n+1;i++){
            if(a[i-1] > a[i] && a[i+1] > a[i])
                pikes++;
            if(a[i-1] < a[i] && a[i+1] < a[i])
                pikes++;
        }
        cout << pikes << "\n";
    }
    return 0;
}
