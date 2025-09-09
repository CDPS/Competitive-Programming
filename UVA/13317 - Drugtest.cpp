#include <bits/stdc++.h>

using namespace std;

bool a[10001];
int MAX = 10000;

void calc(){
    int p2 = 4;
    a[0] = 0; a[1] = a[2] = 1;
    for(int i=3,j=0;i<=MAX;i++){
        a[i] =  !a[p2 - i];
        if(i == p2) p2*=2;
    }
}

int main(){

    calc();
    int n,q;

    while(cin >> n >> q){

        if(n == 0 && q ==0) break;

        while(q--)
            cin >> n, cout << ( a[n]? "A" : "P") ;
        cout <<"\n";
    }
    return 0;
}
