#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main(){

    int n,s,t;
    scanf("%d %d %d",&n,&s,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int ans =0;
    bool first=true;
    int idx =s;
    while(idx!=t ){
        if(idx==s && !first){ printf("-1\n");return 0; }
        first=false;
        idx = a[idx];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
