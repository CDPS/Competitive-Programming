#include <bits/stdc++.h>

using namespace std;

int main(){

    double a [5] = {4.00,4.50,5.00,2.00,1.50};

    int n,c;
    cin >> n >> c;

    printf("Total: R$ %.2lf\n",a[n-1]*c);

    return 0;
}
