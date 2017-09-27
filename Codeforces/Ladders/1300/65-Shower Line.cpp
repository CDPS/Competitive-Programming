#include <bits/stdc++.h>

using namespace std;

long long m[5][5];

long long calc(vector<int> &a){

    long long res=0;

    for(int i=0;i<5;i++){

        for(int j=i;j<4;j+=2){
            int u = a[j];
            int v = a[j+1];

            res+= m[u][v];
            res+= m[v][u];
        }
    }
    return res;
}

int main(){

    vector<int> v;

    for(int i=0;i<5;i++)
        v.push_back(i);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cin >> m[i][j];
    }

    long long res=-1;

    do{
        long long r = calc(v);
        if(r>res)res=r;
    }while(next_permutation(v.begin(),v.end()));

    cout << res << "\n";
    return 0;
}
