#include <bits/stdc++.h>

using namespace std;

int t =1, n;
int a[100000];

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int solve(){

    fin >> n;
    for(int i=0;i<n;i++) fin >> a[i];
    sort(a , a + n);

    int ans = -1;
    for(int j=0, i = 0; j<n; j++){
        while(  a[j] > 2*a[i])
            i++;
        ans = max(ans, j-i+1);
    }

    return n - ans;
}

int main(){

    t = 1;
    while(t--)
        fout << solve() << "\n";

    return 0;
}
