#include <bits/stdc++.h>

using namespace std;

int h[18];
int m[18][13];

int n,b,hs,w;

int getMinPrice(){

    int mini=1000000;
    for(int i=0;i<w;i++){
        for(int j=0;j<hs;j++)
            if(m[j][i]>=n)
                mini=min(mini,h[j]*n);
    }
    return mini;
}

int main(){

    while(cin >> n >> b >> hs >> w){

        int cost;

        for(int i=0;i<hs;i++){
            cin >> cost; h[i]=cost;
            for(int j=0;j<w;j++)
                cin >> m[i][j];
        }

        int mini = getMinPrice();

        if(mini<=b)
            cout  << mini << "\n";
        else
            cout << "stay home\n";
    }
    return 0;
}
