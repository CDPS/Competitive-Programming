#include <bits/stdc++.h>

using namespace std;

int t= 1, n, k;
int a[100000];

int solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=k;i<n;i++)
        a[i]+=a[i-k];

    int ans  = 1, mini = a[n-k];
    for(int i=n-k, index = 1; i< n;i++, index++)
        if(a[i] < mini)
            ans = index, mini = a[i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;
}
