#include <bits/stdc++.h>

using namespace std;


bool f(int n){
    vector<int> v (10,0);
    while(n){ int d = n%10; n/=10; v[d]++; }
    for(int i=0;i<10;i++)if(v[i]>1)return false;
    return true;
}

int main(){
    int n ;
    cin  >> n; n++;

    while(!f(n)){n++;}
    cout << n << "\n";
    return 0;
}
