#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;

    int maxi = -1;

    for(int i=0; (i*a) <=n;i++){
        for(int j = 0; (a*i)+(j*b)<=n;j++){
            if((n-  ( (a*i) + (b*j) ) )%c==0){
                maxi = max(maxi, i + j +  ((n-  ( (a*i) + (b*j) ) )/c)  );
            }
        }
    }

    cout << maxi << "\n";
    return 0;
}
