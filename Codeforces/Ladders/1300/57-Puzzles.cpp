#include <bits/stdc++.h>

using namespace std;

int a[50];
int main(){

    int n,m;
    scanf("%d %d",&n,&m);


    for(int i=0;i<m;i++)
        scanf("%d",a+i);
    sort(a,a+m);

    int mini= 1000000;

    for(int i=0;i<=m-n;i++){
        mini = min(mini,  a[ n-1+i]- a[i]);
    }
    printf("%d\n",mini);
    return 0;
}
