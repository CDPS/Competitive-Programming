#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> e,o,z;
    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x<0)      o.push_back(x);
        else if(x>0) e.push_back(x);
        else         z.push_back(x);
    }

    if(e.size()==0){
        int y = o[o.size()-1];
        e.push_back(y);
        o.pop_back();
        y = o[o.size()-1];
        e.push_back(y);
        o.pop_back();
    }

    if(o.size()%2==0){
        int y = o[o.size()-1];
        z.push_back(y);
        o.pop_back();
    }
    printf("%d",o.size());
    for(int i=0;i<o.size();i++) printf(" %d",o[i]);
    printf("\n");
    printf("%d",e.size());
    for(int i=0;i<e.size();i++)printf(" %d",e[i]);
    printf("\n");
    printf("%d",z.size());
    for(int i=0;i<z.size();i++)printf(" %d",z[i]);
    printf("\n");
    return 0;
}
