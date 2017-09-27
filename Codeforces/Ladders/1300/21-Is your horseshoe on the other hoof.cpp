#include <bits/stdc++.h>

using namespace std;

long a[4];

int main(){

    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);

    sort(a,a+4);

    map<long, int> mp;
    for(int i=0;i<4;i++)
        mp[ a[i] ]++;

    map<long, int>::iterator it;
    int res=0;
    for(it = mp.begin();it!=mp.end();it++) res+= (it->second)-1;

    printf("%d\n",res);

    return 0;
}
