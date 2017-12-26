#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,x,y;
    scanf("%d",&t);

    vector< pair<int,int> > v;
    while(t--){
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end());

    bool f = false;
    for(int i=0;i<v.size()-1;i++){
        if(v[i].first < v[i+1].first && v[i].second> v[i+1].second)
            f =true;
    }

    printf("%s\n",( f?"Happy Alex":"Poor Alex"));
    return 0;
}
