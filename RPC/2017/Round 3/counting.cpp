#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

int amount[5001];

int comb[50][50];
int dpE[5001][5001];
int dpG[5001][5001];

const long mod = 1000000007;

void init() {
    amount[0] = 0; amount[1] = 0;
    for(int i = 2; i < 5001; i++) {
        set<int> s;
        s.insert(1);

        for(int j = 2; j*j <= i; j++) {
            if(i%j == 0) {
                s.insert(j);
                s.insert(i/j);
            }
        }
        amount[i] = s.size();
    }
}


void initComb() {
    for(int i = 0; i<= 49; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int k = 1; k < i; k++)
            comb[i][k] = ( (comb[i-1][k]%mod)  + (comb[i-1][k-1]%mod) )%mod;
    }
}

void go(){

    for(int n=0;n<=5000;n++)
        for(int k=0;k<=5000;k++)
                dpE[n][k]=0,dpG[n][k]=1;

    for(int n=1;n<=5000;n++){
        for(int k=1;k<=5000;k++){
            if(amount[n] <= k){
                dpE[n][k] =( (dpE[n-1][k]%mod) + (amount[n]%mod) )%mod;
                dpG[n][k] = dpG[n-1][k];
            }else{

                dpE[n][k]= ( (dpE[n-1][k]%mod) + (k%mod) )%mod;
                dpG[n][k]= ( (dpG[n-1][k]%mod) * (comb[amount[n]][k]%mod) )%mod;
            }
        }
    }

}
int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    init();
    initComb();
    go();

    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << dpE[n][k] << " " <<  dpG[n][k] << endline;
    }

    return 0;
}
