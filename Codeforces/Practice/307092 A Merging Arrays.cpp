#include <bits/stdc++.h>

using namespace std;

const int oo = 2e9;
int a[100001], b[100001], c[200001];

int main(){

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    a[n] = b[m] = oo;

    int i =0, j=0;
    while(i<n || j < m ){
        if(a[i]<=b[j]) c[i+j] = a[i],i++;
        else c[i+j] = b[j], j++;
    }

    for(int i=0;i<n+m;i++)
        cout << c[i] << " \n"[i==n+m-1];

    return 0;
}
