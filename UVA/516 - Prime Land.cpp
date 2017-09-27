#include <bits/stdc++.h>

using namespace std;

int m[33001];
vector<int> primes;

void sieve(int n){
    m[0]=m[1]= 0;
    for(int i=2;i<n+1;i++)
        m[i]=1;
    for(int i=2;i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i){
                m[j]=0;
            }
            primes.push_back(i);
        }
    }
}

vector< pair<int,int> > factorize(int n){
    vector< pair<int,int>  > r;
    int idx=0;
    int p= primes[idx];

    while( n!=1 && (p*p<=n)  ){
        int e =0;
        while( n%p==0){ n/=p; e++; }
        if(e) r.push_back(make_pair(p,e));
        p = primes[++idx];
    }
    if(n!=1) r.push_back(make_pair(n,1));
    return r;
}

int powW(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)
        r*=a;
    return r;
}

int main(){

    sieve(33000);

    string s;
    stringstream ss;
    int a,b;
    while(getline(cin,s)){
        if(s[0]=='0')
            break;
        int n=1;
        ss.clear();
        ss.str("");
        ss << s;
        while(ss  >> a >> b){ n*=powW(a,b); }
        vector< pair<int,int> > f = factorize(n-1);
        int m = f.size()-1;
        for(int i=m; i>=0;i--){
            if(i == f.size()-1)
                printf("%d %d",f[i].first,f[i].second);
            else
                printf(" %d %d",f[i].first,f[i].second);
        }
        printf("\n");
    }
    return 0;
}
