#include <bits/stdc++.h>

using namespace std;

long long a[9];

int main(){

    while(cin >> a[0]){

        long long mini=a[0]; string s="";

        for(int i=1;i<9;i++) cin >> a[i],mini+=a[i];


        if(mini> a[3]+a[6]+a[2]+a[8]+a[1]+a[4]){
            mini=a[3]+a[6]+a[2]+a[8]+a[1]+a[4];
            s="BCG";
        }

        if(mini > a[3]+a[6]+a[2]+a[5]+a[1]+a[7]){
            mini = a[3]+a[6]+a[2]+a[5]+a[1]+a[7];
            s="BGC";
        }

        if( mini > a[5]+a[8]+a[0]+a[6]+a[1]+a[4] ) {
            mini = a[5]+a[8]+a[0]+a[6]+a[1]+a[4];
            s="CBG";
        }

        if(mini > a[5]+a[8] + a[1] + a[7] + a[0]+a[3]){
            mini = a[5]+a[8] + a[1] + a[7] + a[0]+a[3];
            s="CGB";
        }
        if(mini > a[4] +a[7] + a[0] + a[6] + a[2] + a[5]){
            mini  = a[4] +a[7] + a[0] + a[6] + a[2] + a[5];
            s ="GBC";
        }
        if(mini > a[4] + a[7] + a[2] + a[8] + a[0] + a[3]){
            mini = a[4] + a[7] + a[2] + a[8] + a[0] + a[3];
            s="GCB";
        }
        cout << s << " " << mini << "\n";
    }
    return 0;
}
