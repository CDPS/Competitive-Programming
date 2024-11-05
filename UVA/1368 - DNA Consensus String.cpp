#include <bits/stdc++.h>

using namespace std;

int acc[1000][4];

int f(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m; string s;
    cin >> t;

    while(t--){

        memset(acc, 0, sizeof acc);
        cin >> m >> n;

        for(int i=0;i<m;i++){
            cin >> s;
            for(int j=0;j<n;j++){
                acc[j][f(s[j])]++;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int maxi =  max(acc[i][0],max(acc[i][1], max(acc[i][2],acc[i][3])));
            ans += (acc[i][0]+ acc[i][1]+acc[i][2]+acc[i][3]) - maxi;
            if(acc[i][3] == maxi) s[i]= 'T';
            if(acc[i][2] == maxi) s[i]= 'G';
            if(acc[i][1] == maxi) s[i]= 'C';
            if(acc[i][0] == maxi) s[i]= 'A';
        }

        cout << s   << "\n";
        cout << ans << "\n";
    }
    return 0;
}
