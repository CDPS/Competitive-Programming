#include <bits/stdc++.h>

using namespace std;

int a[12];
int b[12];

int main(){

    int n, caseno = 1;
    while(cin >> n && n >= 0){

        for(int i=0;i<12;i++)
            cin >> a[i];
        for(int i=0;i<12;i++)
            cin >> b[i];

        cout << "Case " << caseno++ << ":\n";
        for(int i=0;i<12;i++){
            if(b[i]>n){
                cout << "No problem. :(" << "\n";
            }else{
                n-=b[i];
                cout << "No problem! :D" << "\n";
            }
            n+=a[i];
        }
    }
    return 0;
}
