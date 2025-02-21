#include <bits/stdc++.h>

using namespace std;

int n;

struct node{
    string x;
    node(string x) : x(x){}
    bool operator < (const node &a ) const{
        return x + a.x < a.x + x;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> n;

    vector<node> v;
    for(int i=0;i<n;i++)
        cin >> s, v.push_back(node(s));
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++)
        cout << v[i].x;
    cout << "\n";
    return 0;
}
