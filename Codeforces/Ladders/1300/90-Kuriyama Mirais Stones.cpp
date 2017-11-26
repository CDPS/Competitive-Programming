#include <bits/stdc++.h>

using namespace std;

long long u[100001],v[100001];
int main(){

    int n,m,l,h,op;
    cin >> n;

    for(int i=1;i<=n;i++)
        cin>>v[i],u[i]=v[i];
    sort(u,u+n+1);

    u[0]=v[0]=0;
    for(int i=1;i<=n;i++)
        v[i]=v[i]+v[i-1],u[i]=u[i]+u[i-1];

    long long r;
    cin >> m;
    while(m--){
        cin >> op >> l>> h;
        r= (op==1)?v[h]-v[l-1]:u[h]-u[l-1];
        cout << r << "\n";
    }
    return 0;
}
