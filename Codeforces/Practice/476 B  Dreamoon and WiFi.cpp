#include <bits/stdc++.h>

using namespace std;

string s, t;

int nCk[35][35];
void precalc(){
    for (int i = 0; i < 35; i++)
        nCk[i][0] = 1;
    for (int i = 0; i < 35; i++)
        for (int j = 1; j <= i; j++)
            nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
}

double solve(){

    cin >> t >> s;

    int n = t.size(), target = 0;
    for(int i =0; i <n; i++)
        target = (t[i]=='+')? target + 1 : target - 1;

    int curr = 0, k = 0;
    for(int i =0; i < n; i++){
        if(s[i]== '+') curr++;
        if(s[i]== '-') curr--;
        if(s[i]== '?') k++;
    }

    if(k == 0)
        return curr == target;

    int need = (k + target - curr)/2;

    if( need > k)
        return 0;

    int top  = nCk[k][need];
    int bottom = (1<<k);

    return double(top)/double(bottom);
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(12);

    precalc();
    cout << solve() << "\n";

    return 0;
}
