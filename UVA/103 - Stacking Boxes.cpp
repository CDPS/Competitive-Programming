#include <bits/stdc++.h>

using namespace std;

struct node{
    vector<int> v; int index;
    node(vector <int> a,int b){ v= a; index=b;sort(v.begin(),v.end()); }

    bool operator < (const node &a )const{
        for(int i=0;i<v.size();i++)
            return  v[i] < a.v[i];
    }
};

int n,m;
bool fits(node a, node b){
    for(int i=0;i<m;i++)
        if( a.v[i] >= b.v[i] ) return 0;
    return 1;
}

vector<node> a;

void dp(){

    vector< vector< int> > l(n);

    l[0].push_back(a[0].index);

    int maxi=1,mii=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++)
            if( fits(a[j],a[i]) && (l[i].size()< l[j].size()+1) )
                l[i]=l[j];
        l[i].push_back(a[i].index);
        if(l[i].size()>maxi)
            maxi=l[i].size(),mii=i;
    }

    cout << maxi << "\n";
    for(int j=0;j<l[mii].size();j++){
        if(j) cout<< " " << l[mii][j];
        else cout << l[mii][j];
    }
    cout << "\n";
}

int main(){

    while(cin >> n >> m){
        vector<int> v(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> v[j];
            a.push_back(node(v,i+1) );
        }
        sort(a.begin(),a.end());
        dp();
        a.clear();
    }
    return 0;
}
