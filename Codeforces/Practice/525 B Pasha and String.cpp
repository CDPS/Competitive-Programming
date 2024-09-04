#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    int n,m, x;
    string s;

    cin >> s >> m;

    n = s.size();

    while(m--)
        cin >> x, a[x-1]++;

    for(int i=1;i<n/2;i++)
        a[i]+=a[i-1];

    for(int i=0;i<n/2;i++)
        if(a[i]%2) swap(s[i], s[n-1-i]);

    cout << s << "\n";

    return 0;
}
