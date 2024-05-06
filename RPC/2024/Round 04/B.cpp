#include <bits/stdc++.h>

using namespace std;

int a,b,r;

bool exists(){
    for(int i = 1; i<=150;i++)
        for(int j=1;j<=150;j++)
            if((i * a) + (j*b) == r )
                return true;
    return false;
}

int main(){

    cin >> r >> a >> b;
    cout << exists() << "\n";
    return 0;
}

