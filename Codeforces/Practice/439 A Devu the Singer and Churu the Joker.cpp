#include <bits/stdc++.h>

using namespace std;

int t= 1, n, w, x;

int solve(){

    cin >> n >> w;

    int sum =0;
    for(int i=0; i <n; i++)
        cin >> x, sum+=x;

    w-= sum + ( (n-1)*10);

    if(w <0 ) return -1;

    return ((n-1)*2) + (w/5);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
