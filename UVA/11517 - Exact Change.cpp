#include <bits/stdc++.h>

using namespace std;

const int inf = 20000000;

long n,m,sum;

map<int,int> coins;

void dp(){

    vector< vector<long > > memo(coins.size()+1,vector<long> ( sum+1,inf));
    memo[0][0]=0;
    int i=1;
    map<int,int>::iterator it;
    int maxi=inf,idx =-1;
    for(it=coins.begin();it!=coins.end();it++,i++){
        int x = it->first,y = it->second;
        for(int l=0;l<sum;l++) memo[i][l]=memo[i-1][l];
        for(int j =1;j<=y;j++)
            for(int k=sum;k>=x*j;k--){
                memo[i][k]= min(memo[i][k], j + memo[i-1][k-(x*j)]);
                if(memo[i][k]!=inf && k>=n) maxi = min(maxi,k);
            }
    }

    while(memo[coins.size()][n]==inf) n++;
    cout << n << " "<< memo[coins.size()][n] << "\n";
}

int main(){

    int t,aux;
    cin >> t;
    while(t--){
          cin >> n;
          cin >> m;
          sum=0;
          for(int i=0;i<m;i++)
            cin >> aux,coins[aux]++,sum+=aux;
          dp();
          coins.clear();
    }
    return 0;
}
