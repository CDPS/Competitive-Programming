#include <bits/stdc++.h>

using namespace std;

int m[1001];

void criba(int n){

    memset(m,1,n+1);
    m[1]=1;

    for(long long i=2;i*i<=n;i++){
        if(m[i]){
            for(long long j=i+i;j<=n;j+=i){
                m[j]=0;
            }
        }
    }
}

vector<int> go(int n){
    vector<int> r;
    for(int i=0;i<=n;i++)
        if(m[i])r.push_back(i);
    return r;
}

int main(){

    criba(1000);
    int n,c;
    while(scanf("%d %d",&n,&c)==2){
        vector<int> v = go(n);
        int m;
        if(v.size()%2) m= (c*2) -1;
        else m= 2*c;

        if(m>=v.size()){
            printf("%d %d:",n,c);
            for(int i=0;i<v.size();i++){
                printf(" %d",v[i]);
            }
            printf("\n\n");
        }
        else{
            int i=0;
            int j= (v.size()/2)-c;
            if(v.size()%2)j++;
            printf("%d %d:",n,c);
            while(i<m){
                printf(" %d",v[j]);
                i++;
                j++;
            }
            printf("\n\n");
        }

    }
    return 0;
}
