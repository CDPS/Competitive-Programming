#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int t,caseno=1;;
    scanf("%d",&t);
 
    while(t--){
        long long n,m;
        scanf("%lld %lld",&n,&m);
        long long fac= n-m;
 
        if(fac<=m)
            printf("Case %d: impossible\n",caseno++);
        else{
                set<long long > facts;
                for(long long i=1;i*i<=fac;i++){
                    if(fac%i==0){
                            facts.insert(i);
                            facts.insert(fac/i);
                    }
                }
 
                set<long long >::iterator it;
                printf("Case %d:",caseno++);
                for(it=facts.begin(); it!=facts.end();it++){
                    if(*it > m)
                        printf(" %lld",*it);
                }
                printf("\n");
        }
    }
    return 0;
}
