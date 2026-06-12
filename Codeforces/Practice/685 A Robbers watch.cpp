#include <bits/stdc++.h>

using namespace std;

int get(int x ){

    if(x == 0) return 1;

    int ans = 0;
    while(x > 0)
        ans++, x/=7;

    return ans;
}

bool check(int h, int m, int size_h, int size_m){

    int mask = 0;
    for(int i=0; i < size_h;i++){
        int d = h % 7;
        if ((mask & (1 << d)) != 0) return false;
        mask |= (1 << d);
        h/=7;
    }

    for(int i=0; i < size_m; i++){
        int d = m % 7;
        if ((mask & (1 << d)) != 0) return false;
        mask |= (1 << d);
        m/=7;
    }
    return true;
}

int t = 1, n, m;

int solve(){

    cin >> n >> m;

    int size_n = get(n-1);
    int size_m = get(m-1);

    if(size_n + size_m > 7) return 0;

    int ans = 0;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            ans+= check(i, j, size_n, size_m);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";
    return 0;
}
