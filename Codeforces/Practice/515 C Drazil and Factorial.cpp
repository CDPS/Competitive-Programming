#include <bits/stdc++.h>

using namespace std;

int acc[10];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n; string s;
    cin >> n >> s;

    for(int i=0;i<n;i++)
        acc[s[i]-'0']++;

    for(int i=2;i<=8;i++)
        for(int j=i+1;j<=9;j++)
            acc[i]+=acc[j];

    acc[2] += (acc[4]*2) + (acc[8]*3) + acc[6];
    acc[3] += (acc[9]*2) +  acc[6];

    acc[5]-=acc[7];
    acc[3]-=acc[7]*2;
    acc[2]-=acc[7]*4;
    acc[3]-=acc[5];
    acc[2]-=acc[5]*3;
    acc[2]-=acc[3];


    acc[4] = acc[8] = acc[9] = acc[6] = 0;

    string ans = "";

    for(int i=7;i>=2;i--)
        for(int j=0;j<acc[i];j++)
            ans+= i+'0';

    cout << ans << "\n";

    return 0;
}

