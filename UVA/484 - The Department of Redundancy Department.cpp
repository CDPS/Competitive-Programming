#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
map<int,int> idx;

int main(){

    int n;
    int i=0;
    while(scanf("%d",&n)==1){
        if(mp.find(n)==mp.end()){
            idx[i]=n;
            i++;
        }
        mp[n]++;
    }

    map<int,int>::iterator it;

    for(it=idx.begin();it!=idx.end();it++){
        int x = it->second;
        printf("%d %d\n",x,mp[x]);
    }
    return 0;
}
