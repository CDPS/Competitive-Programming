#include<bits/stdc++.h>

using namespace std;

int main(){

    int t, caseno=1;

    scanf("%d",&t);

    while(t--){
        long n;
        scanf("%ld",&n);
        long aux=0;
        long unidad;
        long original = n;
        while(n>0){
            unidad=n%10;
            aux=(aux*10) + unidad;
            n/=10;
        }

        if(aux==original){
            printf("Case %d: Yes\n",caseno++);
        }else{
            printf("Case %d: No\n",caseno++);
        }
    }

    return 0;
}
