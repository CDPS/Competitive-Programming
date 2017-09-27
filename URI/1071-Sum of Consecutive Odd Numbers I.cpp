#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin >> n;
    cin >> m;
    if(n>m)
        swap(n,m);

    if(n%2==0)
        n++;
    else
        n+=2;

    int res=0;
    for(int i=n;i<m;i+=2)
        res+=i;

    printf("%d\n",res);
    return 0;
}
