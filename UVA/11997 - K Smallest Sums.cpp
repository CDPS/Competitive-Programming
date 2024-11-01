#include <bits/stdc++.h>

using namespace std;

struct node{
    int i,j,x;
    node(int i,int j, int x) : i(i),j(j), x(x){}
    bool operator < (const node &a)const{ return x > a.x;}
};

int n;
int a[750], b[750], c[750];

void solve(){
    priority_queue<node> pq;
    set<pair<int, int>> v;
    pq.push(node(0,0,a[0]+b[0]));
    int k = n, i = 0;
    while(k--){
        node u = pq.top(); pq.pop();
        c[i++] = u.x;
        if (u.i + 1 < n && !v.count(make_pair(u.i + 1, u.j)))
            pq.push(node(u.i+1, u.j, a[u.i+1] + b[u.j])), v.insert(make_pair(u.i + 1, u.j));
        if (u.j + 1 < n && !v.count(make_pair(u.i, u.j+1)))
            pq.push(node(u.i, u.j+1, a[u.i] + b[u.j+1])), v.insert(make_pair(u.i, u.j+1));
    }
    for(int j=0;j<n;j++) a[j] = c[j];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n){

        for(int i=0;i<n;i++) cin >> a[i];

        sort(a, a+n);
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++) cin >> b[j];
            sort(b, b + n);
            solve();
        }

        for(int i=0;i<n-1;i++) cout << a[i] << " ";
        cout << a[n-1] << "\n";
    }
    return 0;
}
