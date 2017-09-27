#include <bits/stdc++.h>

using namespace std;


int a[2];
int b[2];

int main(){

    for(int i=0;i<2;i++){
        a[i]=b[i]=0;
    }

    int n;
    scanf("%d",&n);

    int u,v;

    for(int i=0;i<n;i++){
        scanf("%d %d", &u,&v);
        a[u]++; b[v]++;
    }

    printf("%d\n", min(a[0],a[1]) + min(b[0],b[1])  );
    return 0;
}
