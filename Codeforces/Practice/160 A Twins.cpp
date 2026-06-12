#include <bits/stdc++.h>

using namespace std;

int n, k, x;
int a[100];

int solve(){

    cin >> n;
    int sum = 0;
    for(int i=0; i < n ; i++)
        cin >> a[i], sum+= a[i];

    sort(a, a + n, greater<int>());

    int curr_sum = 0, ans = 0;
    for(int i=0;i < n; i++){
        curr_sum += a[i];
        ans++;
        if(  2*curr_sum > sum )
            break;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
