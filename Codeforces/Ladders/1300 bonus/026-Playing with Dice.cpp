#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b;

    cin >> a >> b;

    int wa=0, d=0, wb=0;

    for(int i=1;i<=6;i++){
        int da = abs(i-a);
        int db = abs(i-b);
        if(da< db){
            wa++;
        }else if(db < da){
            wb++;
        }
        else{
            d++;
        }
    }
    cout << wa << " " << d << " " << wb << "\n";
    return 0;
}
