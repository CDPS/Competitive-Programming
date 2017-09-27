#include <bits/stdc++.h>

using namespace std;


int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);
        int sm,a,e,res=0;

        for(int i=0;i<n;i++){
            scanf("%d %d %d",&sm,&a,&e);
            res+= (sm)*e;
        }
        printf("%d\n",res);
    }
    return 0;
}
