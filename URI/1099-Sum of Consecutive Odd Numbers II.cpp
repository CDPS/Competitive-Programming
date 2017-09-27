#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);


    while(t--){

        int n,m;
        scanf("%d %d",&n,&m);

        if(n>m)
            swap(n,m);

        int res=0;
        for(int i=n+1;i<=m-1;i++){
            if(i%2)
                res+=i;
        }

        printf("%d\n",res);
    }
    return 0;
}
