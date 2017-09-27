#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    map< pair<int,int>,int > mp;

    int u,v;
    for(int i=0;i<n;i++){
        scanf("%d %d",&u,&v);
        mp[ make_pair(u,v)]++;
    }

    map< pair<int,int>,int >::iterator it;

    int maxi=-1;
    for(it = mp.begin();it!=mp.end();it++){
        if(maxi< it->second) maxi =  it->second;
    }

    printf("%d\n",maxi);
    return 0;
}
