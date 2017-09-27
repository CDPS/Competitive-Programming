#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    if(n%2)printf("-1\n");
    else
      for(int i=2;i<=n;i+=2)
           printf("%d %d%c", i, i-1, i==n? '\n': ' ');
    return 0;
}
