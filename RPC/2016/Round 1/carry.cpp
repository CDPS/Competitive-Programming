#include <bits/stdc++.h>

using namespace std;

int main(){


    int n;
    scanf("%d",&n);

    map<int,string> mp;

    mp[61]="Brasilia";
    mp[71]="Salvador";
    mp[11]="Sao Paulo";
    mp[21]="Rio de Janeiro";
    mp[32]="Juiz de Fora";
    mp[19]="Campinas";
    mp[27]="Vitoria";
    mp[31]="Belo Horizonte";

    if(mp.find(n)!= mp.end())
        cout << mp[n] << "\n";
    else
        cout << "DDD nao cadastrado" << "\n";

    return 0;
}



