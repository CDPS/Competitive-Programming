#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int u,v,w;
    int res=0;
    for(int i=0;i<n;i++){

        scanf("%d %d %d",&u,&v,&w);
        u+=v+w;
        if(u>=2)
            res++;
    }
    printf("%d\n",res);
    return 0;
}
