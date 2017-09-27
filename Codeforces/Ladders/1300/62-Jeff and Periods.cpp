#include <bits/stdc++.h>

using namespace std;


struct node {
    int n,idx;
    node ( int a, int b){
        n=a; idx=b;
    }

    bool operator < ( const node &a) const {
        if(n==a.n)
            return  idx< a.idx;
        return n < a.n;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    vector <node > v;
    vector <int > c(100001,0);

    int ai;

    for(int i=0;i<n;i++){
        scanf("%d",&ai);
        v.push_back(node(ai,i) );
        c[ ai]++;
    }
    sort(v.begin(),v.end());
    int i=0;

    vector < pair< int, int > > res;
    while(i<n){
        if(c[v[i].n]==1) res.push_back( make_pair(v[i].n, 0) );

        else{
            int d = v[i+1].idx - v[i].idx; i++;
            bool f = true;
            int j=0 , m = c[ v[i].n] -1 ;

            while( j < m){
                if(v[i].idx - v[i-1].idx != d)f=false;
                i++; j++;
            }
            if(f) res.push_back( make_pair( v[i-1].n , d) );
            continue;
        }
        i++;
    }

    printf("%d\n",res.size());
    for(int i=0;i<res.size();i++)
        printf("%d %d\n",res[i].first,res[i].second);
    return 0;
}
