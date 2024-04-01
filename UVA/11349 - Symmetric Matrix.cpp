#include <bits/stdc++.h>

using namespace std;

long long m [100][100];

bool process(int n){

    int mid = n/2 + (n%2);

    bool ans = true;
    for(int i =0;i<mid && ans;i++)
        for(int j=0;j<mid && ans;j++)
            ans &= m[j][i] == m[n-1-j][n-1-i] && m[n-1-j][i] == m[j][n-1-i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,caseno = 1;
    char a,b;
    cin >> t;

    while(t--){
        cin >> a >> b >> n;

        bool ans = true;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> m[i][j], ans &= m[i][j] >= 0;

        if(ans)
            ans = process(n);

        cout << "Test #" << caseno++ << ": " << ( ans? "Symmetric." : "Non-symmetric." ) << "\n";
    }

    return 0;
}
