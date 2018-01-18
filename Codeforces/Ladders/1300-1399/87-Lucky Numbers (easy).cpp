#include <bits/stdc++.h>

using namespace std;

vector<long long> luckies;

void GetLuckies(int idx,int top,long long acc,int fours, int sevens){
    if(idx == top){
        if(fours==sevens)luckies.push_back(acc);
        return;
    }
    GetLuckies(idx+1,top,acc*10 + 4,fours+1,sevens);
    GetLuckies(idx+1,top,acc*10 + 7,fours,sevens+1);
}

int main(){

    for(int i=1;i<=10;i++) GetLuckies(0,i,0,0,0);

    long long n; cin >> n;

    for(int i=0;i<luckies.size();i++){
        if(luckies[i]>=n){
            cout << luckies[i] << "\n"; break;
        }
    }
    return 0;
}
