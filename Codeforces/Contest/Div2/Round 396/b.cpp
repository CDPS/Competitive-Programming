#include <bits/stdc++.h>

using namespace std;


long as[100000];

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> as[i];
    sort(as,as+n);

    for(int i=2;i<n;i++){

        long a = as[i];
        long b = as[i-1];
        long c = as[i-2];

        if(  (a+b > c) && (a+c>b) && (b+c>a)  ){
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
