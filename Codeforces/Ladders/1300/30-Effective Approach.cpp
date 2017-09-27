#include <bits/stdc++.h>

using namespace std;

struct node{
    int v;
    int idx;

    node(int a, int b){
        v=a;
        idx=b;
    }
    bool operator < (const node &a)const{
        return v < a.v;
    }
};

int main(){

    int n,m;
    cin >> n;

    int a;
    vector < node > v;

    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(node(a,i));
    }

    sort(v.begin(), v.end());
    cin >> m;
    long long r1=0,r2=0;

    int q;

    for(int i=0;i<m;i++){
        cin >> q;
        q--;
        r1 += (v[q].idx +1);
        r2 += n-v[q].idx;
    }

    cout << r1 << " " << r2 <<"\n";
    return 0;
}
