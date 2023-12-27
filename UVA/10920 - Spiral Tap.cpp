#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    long long d, n;

    while(cin >> d >> n && d != 0 && n!=0 ){

        long long x = d/2, y = d/2;
        long long i = 1, acc = 1 , vacc = 0, hacc = 0;
        bool flag = true;

        while(i<n){

            if(flag)
                x = (acc%2)? x + 1: x - 1, vacc++;
            else
                y = (acc%2)? y - 1: y + 1, hacc++;

            if(vacc==acc)
                vacc=0, flag=false;
            if(hacc==acc)
                acc++, hacc=0,flag=true;

            i++;
        }

        cout << "Line = " << x+1 << ", column = " << y+1 << ".\n";
    }
    return 0;
}
