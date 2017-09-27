#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    if(n%2)
        n+=2;
    else
        n+=1;

    for(int i=0;i<6;i++){
        printf("%d\n",n);
        n+=2;
    }
    return 0;
}
