#include <bits/stdc++.h>

using namespace std;

vector<long long> luckies;
vector<long long> acc;

void Generate(int idx, int top, long long acc){

    if(idx == top){luckies.push_back(acc);return;}

    Generate(idx+1,top,acc*10 + 4);
    Generate(idx+1,top,acc*10 + 7);
}

void preCalc(){
    for(int i=1;i<=10;i++) Generate(0,i,0);
    acc.push_back(4);
    for(int i=1;i<luckies.size();i++)
        acc.push_back( luckies[i] - luckies[i-1]);
}

int Find(long long x){
    int i =0;
    while(luckies[i]<x)i++;
    return i;
}

int main(){

    preCalc();

    long long l,h,ans,x,r;
    int idx;

    cin >> l >> h;

    if(Find(l)==Find(h)){
        idx = Find(l);
        ans = (h-l+1ll)*(luckies[idx]);
    }else{

        idx = Find(l);
        x= luckies[idx];
        ans = x*(x-l+1);

        r=x+1;
        idx = Find(x+1);
        x = luckies[idx];

        while(x<h){
            ans = ans + (x*acc[idx]);
            r=x+1;
            idx = Find(x+1);
            x   = luckies[idx];
        }

        idx = Find(h);
        x = luckies[idx];
        ans = ans +( (h-r+1)*x );
    }

    cout << ans << "\n";
    return 0;
}
