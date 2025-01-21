#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pr;

int calcPerimeter(pr botom, pr top){
    return 2*((top.first-botom.first)+(top.second-botom.second));
}

pr getTop(pr botom,int  m){
    return { botom.first + m, botom.second + m };
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        int x, y;

        cin >> x >> y;

        pr bx = {x,y};
        pr tx = getTop(bx, m);

        int ans = calcPerimeter(bx, tx);
        for(int i=0;i<n-1;i++){
            cin  >> x >> y;
            pr by = {x+= bx.first, y+=bx.second};
            pr ty = getTop(by, m);
            ans+= calcPerimeter(by,ty);
            ans-= calcPerimeter( max(bx,by), min(tx,ty));
            bx = by; tx =ty;
        }
        cout << ans << "\n";
    }
    return 0;
}
