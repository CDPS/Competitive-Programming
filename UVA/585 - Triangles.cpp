#include <bits/stdc++.h>

using namespace std;

string g[100];
int n;

int getArea(int x, int y, int level){
    bool keep= true;
    int acc = 0;
    for(int i=0;i<level && keep;i++){
        for(int j= y-i;j<=y+i && keep;j++){
            keep = g[x-i][j] == '-';
            acc++;
        }
    }
    return keep? acc : 0;
}

int getAreaP(int x, int y, int level){
    bool keep= true;
    int acc = 0;
    for(int i=0;i<level && keep;i++){
        for(int j= y-i;j<=y+i && keep;j++){
            keep = x+i < n && j>=0 && j<g[x+i].size() && g[x+i][j] == '-';
            acc++;
        }
    }
    return keep? acc : 0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int caseno= 1;

    while(cin >> n && n){

        cin.ignore();

        for(int i=0;i<n;i++)
            getline(cin, g[i]);

        int x = n-1;
        int y = g[x].size() -1;

        int ans=0;
        bool keep = false;

        for(int level=n;level>=1 &&!keep;level--){
            for(int i= 0;i<=n-level && !keep;i++){
                for(int j= y-i;j<=y+i && !keep;j+=2){
                    ans =getArea(x-i,j,level);
                    keep = ans !=0;
                }
            }
        }

        for(int level=(n/2 + n%2);level>=1;level--){
            for(int i= 0;i<n;i++){
                for(int j= i+1;j<g[i].size();j+=2){
                    ans = max( ans , getAreaP(i,j,level) );
                }
            }
        }
        cout << "Triangle #" << caseno++ << "\n";
        cout << "The largest triangle area is " << ans << "." << "\n";
        cout << "\n";
    }
    return 0;
}
