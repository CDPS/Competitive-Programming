#include <bits/stdc++.h>

using namespace std;

int n,indexs[21], a[21],memo[21][21];

int dp(int ant,int i){

    if(i==n+1) return 0;

    if(memo[i][ant]!=-1) return memo[i][ant];

    if( indexs[a[i]] <  indexs[ ant ] ) return dp(ant,i+1);

    return  memo[i][ant] = max( dp(ant,i+1) ,  dp( a[i] , i+1 ) + 1 ) ;
}

int main(){

    string line;
    int aux; indexs[0]=0;

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> indexs[i];
    cin.ignore();

    while(getline(cin,line)){

        stringstream ss(line);
        for(int i=1;i<=n;i++)
            ss >> aux, a[aux]= i;

        memset(memo,-1, sizeof memo);
        cout << dp(0,1)<< "\n";
    }
    return 0;
}
