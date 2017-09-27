#include <bits/stdc++.h>

using namespace std;

struct node{
    long m,f,w;

    node(long a,long b,long c){
        m=a; f=b; w=a+c;
    }

    bool operator < (const node &a) const{
        return m < a.m;
    }
};

vector<node> v;
vector<long> ms;

long long memo[300010];

long long dp(long idx){

    if(idx==v.size())
        return 0;

    if(memo[idx]!=-1) return memo[idx];

    long long ans = max ( dp(idx+1) , v[idx].f + dp( long( lower_bound(ms.begin(),ms.end(), v[idx].w )-ms.begin() )));

    return memo[idx] = ans;
}


int main(){

    long n;
    scanf("%ld",&n);

    long m,f,w;

    for(int i=0;i<n;i++){
        scanf("%ld %ld %ld",&m,&f,&w);
        v.push_back(node(m,f,w));
        ms.push_back(m);
    }

    ms.push_back(1000001);

    sort(v.begin(),v.end());
    sort(ms.begin(),ms.end());

    for(long i=0;i<n;i++)
        memo[i]=-1;

    printf("%lld\n",dp(0));
    return 0;
}
