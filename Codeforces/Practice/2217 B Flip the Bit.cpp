#include <bits/stdc++.h>

using namespace std;

int t, n, k, p0;
bool a[200000];

int f(int idx, int curr){
    return curr %2 ? !a[idx] : a[idx];
}

int solve(){

    cin >> n >> k;
    for(int i = 1; i <=n; i++) cin >> a[i];
    cin >> p0;

    int target = a[p0];

    int i = 1, j = n, ans = 0;
    while(i < j){

        while( f(i, ans) == target && i< p0)
            i++;
        while( f(j, ans) == target && j > p0)
            j--;


        if(i != p0 || j!= p0)
            ans++;

        if(i < p0 ) i++;
        if(j > p0)  j--;

    }

    return ans + (f(p0, ans) != target);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
