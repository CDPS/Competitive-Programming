#include <bits/stdc++.h>

using namespace std;

string a[100], b[100], b90[100], b180[100], b270[100];

int n,m;

void r(string s[100], string t[100]){
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            t[j][m-1-i] = s[i][j];
}

int acc(string s[100], string t[100]){
    int ans =0;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool keep = true;
            for(int k=0;k<m && keep;k++){
                for(int l=0;l<m && keep;l++)
                    keep &= t[k][l] == s[i+k][j+l];
            }
            if(keep)
                ans++;
        }
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(cin >> n >> m && (n||m)){

        for(int i=0;i<n;i++)
            cin >> a[i];

        for(int i=0;i<m;i++)
            cin >> b[i], b90[i] = b180[i] = b270[i] = b[i];

        r(b,b90);
        r(b90,b180);
        r(b180,b270);

        cout <<  acc(a,b) << " " << acc(a,b90) << " " << acc(a,b180) << " " << acc(a,b270) << "\n";
    }
    return 0;
}
