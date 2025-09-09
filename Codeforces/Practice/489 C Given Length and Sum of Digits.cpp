#include <bits/stdc++.h>

using namespace std;

bool dp[101][901];

int main(){

    int n, m;
    cin >> n >> m;

    dp[0][0] = true;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int d=0;d<=9;d++)
                if(j-d >=0)
                    dp[i][j] |= dp[i-1][  j-d ];

    if(n==1 && m==0){
        cout << 0 << " " <<  0 << "\n";
        return 0;
    }

    if(!dp[n][m] || m==0){
        cout << -1 << " " <<  -1 << "\n";
        return 0;
    }


    string mini = "";
    int acc=m;
    for(int i=n;i>=1;i--){
        for(int d=0;d<=9;d++){
            if(i==n && d==0) continue;
            if(acc-d >=0 && dp[i-1][acc -d ] ){
                mini+= d + '0';
                acc-=d;
                break;
            }
        }
    }

    string maxi = "";
    acc=m;
    for(int i=n;i>=1;i--){
        for(int d=9;d>=0;d--){
            if(i==n && d==0) continue;
            if(acc-d >=0 && dp[i-1][acc -d ] ){
                maxi+= d + '0';
                acc-=d;
                break;
            }
        }
    }

    cout << mini << " " << maxi << "\n";

    return 0;
}
