#include <bits/stdc++.h>

using namespace std;

int t, n;

int b[200000];

int solve(){

    cin >> n;

    for(int i=0; i < 2*n ; i++) cin >> b[i];


    vector<int> in_set(n + 1, -1);
    int ans = 0;
    for(int curr=0, i= -1, j=0; curr < 4*n; curr++){

        if(curr%2==0) i++;
        if(curr%2) j++;

        int curr_i = i, curr_j = j;
        while( curr_i >=0 && curr_j< 2*n && b[curr_i] == b[curr_j])
            in_set[ b[curr_i] ] = curr, curr_i--, curr_j++;

        int curr_mex = 0;
        while( in_set[curr_mex] == curr )
            curr_mex++;

        ans = max(curr_mex, ans);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

