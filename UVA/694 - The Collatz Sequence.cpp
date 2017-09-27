#include<bits/stdc++.h>

using namespace std;

int calcTerms(long long a, long long l){
    int n=0;
    while(a!=1ll && a<=l){
        n++;
        if(a%2ll==0) a/=2ll;
        else a = 3ll*a+1ll;

    }
    if(a<=l)
        n++;
    return n;
}

int main(){
    int caseno=1;
    long long a,l;
    while(true){
        scanf("%lld %lld",&a,&l);
        if(a==-1 && l==-1)
            break;
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",caseno++,a,l,calcTerms(a,l));
    }
    return 0;
}
