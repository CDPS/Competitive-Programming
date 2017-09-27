#include <bits/stdc++.h>

using namespace std;

int main(){

    int a;
    int even=0;
    for(int i=0;i<5;i++){
        cin >> a;
        if(a%2==0)
            even++;

    }

    printf("%d valores pares\n",even);

    return 0;
}
