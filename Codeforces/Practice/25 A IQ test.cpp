#include <bits/stdc++.h>

using namespace std;

int evens[2];
int mp[2];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    int n, x;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> x, evens[x%2]++, mp[x%2] = i;

    cout << ( evens[0] == 1? mp[0]+1 : mp[1]+1 ) << "\n";

    return 0;
}

