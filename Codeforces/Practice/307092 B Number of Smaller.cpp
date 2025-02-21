#include <bits/stdc++.h>

using namespace std;

const int oo = 2e9;
int a[100001],b[100001];
int n,m,x;


int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    a[n] = b[m] = oo;

    int i = 0, j = 0;

    while(i <n || j <m ){
        if(a[i] < b[j] ) i++;
        else cout << i <<" \n"[j==m], j++;
    }
    return 0;
}
