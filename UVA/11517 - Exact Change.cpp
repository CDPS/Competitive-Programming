#include <bits/stdc++.h>

using namespace std;

const int inf = 20000000;

int n,m,sum;


map<int,int> coins;
ofstream of("a.txt");

void dp(){


    vector<int> memo(sum+1,inf);
    memo[0]=0;

    map<int,int>::iterator it;
    int maxi = inf;
    for(it=coins.begin();it!=coins.end();it++){
        int x = it->first,y = it->second;
        for(int j = x;j<=sum;j++){
            for(int k=1;k<=y && j>= x*k;k++)
                memo[j] = min( memo[j], k + memo[j-(x*k)] );
            if(memo[j]!=inf && j>n)
                maxi = min(maxi,j);

        }
    }

    if(memo[n]!=inf) of<< n << " "<< memo[n] << "\n";
    else
       of << maxi<< " " << memo[maxi]<< "\n";
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,aux;
    cin >> t;
    while(t--){
          cin >> n;
          cin >> m;
          sum=0;
          for(int i=0;i<m;i++) cin >> aux,coins[aux]++,sum+=aux;
          dp();
          coins.clear();
    }
    return 0;
}
