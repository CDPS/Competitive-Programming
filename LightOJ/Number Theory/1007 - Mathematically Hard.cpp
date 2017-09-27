#include <bits/stdc++.h>
 
using namespace std;
unsigned long long phi[5000001];
 
void criba(int tam){
 
    for(int i=0;i<=tam;i++){
        phi[i]=i;
    }
 
    for(int i=2;i<=tam;i++){
        if(phi[i]==i){
            phi[i]-=1;
            for(int j=i+i;j<=tam;j+=i){
                phi[j]*=(i-1);
                phi[j]/=i;
            }
        }
    }
}
 
int main(){
 
    criba(5000000);
 
    for(int i=1;i<=5000001;i++)
           phi[i]= (phi[i]*phi[i])+phi[i-1];
 
     int t,caseno=1;
     scanf("%d",&t);
 
     while(t--){
            int a,b;
            scanf("%d %d",&a,&b);
            printf("Case %d: %llu\n",caseno++,phi[b]-phi[a-1]);
     }
    return 0;
}
