#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
ull fac[1000001];
 
int m=1000003;
 
ull eb (ull a, ull b){
 
    ull res=1;
    ull x= a%m;
 
    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }
 
    return res;
}
 
int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    fac[0]=1;fac[1]=1;
    for(int i=2;i<1000001;i++){
        fac[i]=  ((i%m)*(fac[i-1]%m))%m;
    }
 
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        ull nCk = ((fac[n]%m)*(eb((fac[k]*fac[n-k]),m-2)%m))%m;
        printf("Case %d: %llu\n",caseno++,nCk);
    }
    return 0;
}
