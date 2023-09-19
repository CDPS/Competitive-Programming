#include <bits/stdc++.h>

using namespace std;


int a[1000];

int main(){

    int n, s, result;
    cin  >> n >> s;

    int f, t;
    for(int i=0;i<n;i++){
        cin >> f >> t;
        a[f-1] = max( t, a[f-1] );
    }

    result = a[s-1];
    for(int i = s-2;i>=0;i--){
        result++;
        if(result < a[i] )
            result= a[i];
    }
    cout  << result + 1 <<  "\n";
    return 0;
}
