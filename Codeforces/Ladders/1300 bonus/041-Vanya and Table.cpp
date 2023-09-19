#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x1,x2,y1,y2;
    cin >> n;
    int res =0;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
               res++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
