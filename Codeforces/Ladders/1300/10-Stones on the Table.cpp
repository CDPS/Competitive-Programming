#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    char c;
    cin >> c;

    char aux= c;
    int res=0;

    for(int i=1;i<n;i++){
        cin >> c;
        if(c == aux)res++;
        aux=c;
    }

    cout << res << "\n";
    return 0;
}
