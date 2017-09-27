#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector< vector<int> > memo;


int dp(int idx, int b){
    if(idx==a.size()) return 0;

    if(memo[idx][b]!=-1)return memo[idx][b];

    if(b < a[idx]) return dp(idx+1,b);

    return memo[idx][b]= max( dp(idx+1,b), 1 + dp(idx+1,a[idx]) );
}

int main(){

    int ai=0,caseno=1;bool first=true;
    while(ai!=-1){
        a.clear();

        while(ai!=-1){
              if(!first)
                a.push_back(ai);
              first=false;
              cin >> ai;
        }
        memo = vector< vector<int> > (a.size(),vector<int>(33001,-1));
        cout << "Test #"<<caseno++ << ":\n";
        cout << "  maximum possible interceptions: "<< dp(0,33000) << "\n";
        cin >> ai;
        if(ai!=-1) cout << "\n";
    }
    return 0;
}
