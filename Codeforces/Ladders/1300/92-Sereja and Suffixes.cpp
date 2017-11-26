#include <bits/stdc++.h>

using namespace std;

int a[100001], b[100001];
set<int> s;

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=n;i>=1;i--){
        if(s.find(a[i])==s.end()) b[i]=1,s.insert(a[i]);
        else b[i]=0;
    }

    b[0]=0;
    for(int i=1;i<n+1;i++) b[i]= b[i]+b[i-1];

    int l;
    while(m--){
        scanf("%d",&l);
        printf("%d\n",b[n]-b[l-1]);
    }
    return 0;
}
