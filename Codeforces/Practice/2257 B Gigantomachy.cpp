#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int get_capacity(vector<int> & v){
    int capacity = v.back();
    for(int i = 0; i < v.size() - 1; i++)
        capacity+= (v[i] - (v[i+1]-1));
    return capacity;
}

int solve(){

    cin >> n >> m;

    vector<int> a(n),  b(m);
    for(int i=0; i < n ; i++) cin >> a[i];
    for(int i=0; i < m ; i++) cin >> b[i];

    int capacity_a = get_capacity(a);
    int capacity_b = get_capacity(b);

    return capacity_a >= capacity_b? 1 : 2;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout <<  solve() << "\n";
    
    return 0;
}