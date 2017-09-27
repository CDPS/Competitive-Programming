#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;

    cin >> n;

    int a = n /365;

    n-= a*365;

    int m = n /30;
    n-= m*30;

    int d = n;
    printf("%d ano(s)\n",a);
    printf("%d mes(es)\n",m);
    printf("%d dia(s)\n",d);
    return 0;
}
