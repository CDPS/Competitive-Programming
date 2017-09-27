#include <bits/stdc++.h>

using namespace std;


int main(){
    vector< pair<int,int> > v;
    int n;

    scanf("%d",&n);

    int x,y,xp,yp;

    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }

    bool f1,f2,f3,f4;
    int res=0;
    for(int i=0;i<n;i++){
        f1 = f2 = f3= f4=0;
        x = v[i].first; y = v[i].second;

        for(int j=0;j<n;j++){
            xp = v[j].first; yp = v[j].second;
            if(j!=i){
                if(xp >x && yp==y)f1=1;
                if(xp<x && yp ==y)f2=1;
                if(xp==x && yp< y)f3=1;
                if(xp==x && yp>y)f4=1;
            }
        }
        if(f1 && f2 && f3 && f4)res++;
    }
    printf("%d\n",res);
    return 0;
}
