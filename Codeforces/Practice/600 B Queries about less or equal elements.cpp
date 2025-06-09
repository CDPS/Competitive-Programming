#include <bits/stdc++.h>

using namespace std;

int a[200001];
int b[200000];

int oo = 1e9 + 7;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;

    for(int i=0;i<n;i++) cin>> a[i];
    a[n] = oo;

    vector<pair<int, int> > v;
    for(int i=0;i<m;i++)
        cin >> x, v.push_back({x,i});

    sort(a, a+n);
    sort(v.begin(), v.end());

    int i =0, j=0;
    while(j<m){
        if(a[i] <= v[j].first )i++;
        else b[v[j].second] = i, j++;
    }

    for(int i=0;i<m;i++)
        cout << b[i] << " \n"[i==m-1];

    return 0;
}

