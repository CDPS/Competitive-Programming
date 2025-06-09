#include <bits/stdc++.h>

using namespace std;

int n;
struct node{
    int a, b;
    node(int a, int b): a(a), b(b){};
    bool operator < (const node &t ) const{
        if(a == t.a) return b < t.b;
        return a < t.a;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, x, y;
    cin >> n;

    vector<node> v;
    for(int i =0;i<n;i++)
        cin >> x >> y, v.push_back(node(x,y));
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0;i<n;i++)
        ans = ans <= v[i].b? v[i].b : v[i].a;

    cout << ans << "\n";

    return 0;
}
