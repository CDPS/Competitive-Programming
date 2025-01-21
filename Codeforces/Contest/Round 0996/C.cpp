#include <bits/stdc++.h>

using namespace std;

map<char,pair<int,int>> mp = {{'D',{1,0}},{'R',{0,1}}};

long long a[1000][1000];
long long b[1000][1000];
long long oo = 2e18;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m;
    string s;
    cin >> t;

    while(t--){
        cin >> n >> m >> s;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j], b[i][j] = 0;

        pair<int,int> acc = {0,0};
        for(int i=0;i<s.size();i++){
            b[acc.first][acc.second] = 1;
            acc.first += mp[s[i]].first;
            acc.second += mp[s[i]].second;
        }
        b[acc.first][acc.second] = 1;

        long long x = 0, temp;
        acc = {0,0};
        for(int i=0;i< s.size();i++){

            long long temp1 = 0;
            for(int j=0;j<m;j++){
                if(j != acc.second){
                    if(!b[acc.first][j])
                         temp1+= a[acc.first][j];
                    else{
                        temp1 = oo; break;
                    }
                }
            }

            long long temp2 = 0;
            for(int j=0;j<n;j++){
                if(j != acc.first){
                    if(!b[j][acc.second])
                         temp2+= a[j][acc.second];
                    else{
                        temp2 = oo; break;
                    }
                }
            }
            temp = min(temp1, temp2);
            a[acc.first][acc.second] = - temp;
            b[acc.first][acc.second] = 0;
            acc.first += mp[s[i]].first;
            acc.second += mp[s[i]].second;
        }


        temp = 0;
        for(int j=0;j<m;j++)
            temp+= a[acc.first][j];
        a[acc.first][acc.second] = -temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout << a[i][j] << " \n"[j==m-1];
        }
    }
    return 0;
}
