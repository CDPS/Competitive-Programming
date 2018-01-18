#include <bits/stdc++.h>

using namespace std;

char g[50][50];

int  xx[4]={1,-1,0,0};
int  yy[4]={0,0,1,-1};

int n,m;

int xs, ys, xe,ye;

string s;

int Find(char x,string mp){
    for(int i=0;i<4;i++)
        if(mp[i]==x)return i;
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
            if(g[i][j]=='S')
                xs = i, ys=j;
            else if(g[i][j]=='E')
                xe= i, ye = j;
        }
    }

    cin >> s;
    int ans =0;
    string mp= "0123";

    do{

        int xsa = xs,ysa= ys;

        for(int i=0;i<s.size();i++){
            int c = Find(s[i],mp);
            xsa = xsa + xx[c];
            ysa = ysa + yy[c];

            if(xsa == xe && ysa == ye){
                ans++;
                break;
            }
            if(xsa<0 || xsa ==n || ysa<0 || ysa==m)
                break;
            if(g[xsa][ysa]=='#')
                break;
        }
    }while(next_permutation(mp.begin(),mp.end()));

    cout << ans << "\n";
    return 0;
}
