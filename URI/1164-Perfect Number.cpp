#include <bits/stdc++.h>

using namespace std;


int main(){

    int t;

    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        int res=0;
        for(int i=1;i<n;i++){
            if(n%i==0)
                res+=i;
            if(res>n)
                break;
        }
        if(res==n){
            printf("%d eh perfeito\n",n);
        }else{
            printf("%d nao eh perfeito\n",n);
        }
    }

    return 0;
}
