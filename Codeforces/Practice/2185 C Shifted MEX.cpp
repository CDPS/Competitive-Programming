#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[3000];
int b[3000];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+ n);

    int mex = -1e9;
    for(int i=0; i<n; i++){

        for(int j=0; j <n ;j++)
            b[j] = a[j] - a[i];

        int curr_mex =0;
        for(int i=0;i<n;i++)
            if(b[i] == curr_mex)
                curr_mex++;

        mex = max(curr_mex, mex);
    }

    return mex;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

