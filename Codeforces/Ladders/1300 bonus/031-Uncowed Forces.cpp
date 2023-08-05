#include <bits/stdc++.h>

using namespace std;

int a[100];

int GetScore(int x, int m, int w){
    return max( (3*x/10), (  ((250-m)*x)/250 ) - (50*w) );
}


int main(){

    int m1,m2,m3,m4,m5;
    int w1,w2,w3,w4,w5;
    int sh,uh;

    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    cin >> w1 >> w2 >> w3 >> w4 >> w5;
    cin >> sh >> uh;


    int score = GetScore(500, m1,w1) +
                GetScore(1000,m2,w2) +
                GetScore(1500,m3,w3) +
                GetScore(2000,m4,w4) +
                GetScore(2500,m5,w5) +
                (sh*100) -
                (uh*50);

    cout << score << "\n";
    return 0;
}

