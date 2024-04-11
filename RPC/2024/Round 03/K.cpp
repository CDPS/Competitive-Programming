#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> words;

int dp[1000000][3][3];

int oo = 10000000;

bool isVowel(char c){
    return c == 'A' ||  c == 'E' ||  c == 'I' ||  c == 'O'||  c == 'U' ||  c == 'Y';
}

int getNextAcc(int acc, char c){
    return isVowel(c) ? 0 : acc+1;
}

int solve(){

    int c =0;
    for(int i=0;i<3;i++){
        c = getNextAcc(c,words[0][i]);
        if(c <= 2)
            dp[0][i][c] = i + 1;
    }

    for(int i=1;i<n;i++){
        if(isVowel(words[i][0])){
            dp[i][0][0] = min({dp[i][0][0], 1 + dp[i-1][0][0], 1 + dp[i-1][0][1], 1+ dp[i-1][0][2],
                                            1 + dp[i-1][1][0], 1 + dp[i-1][1][1], 1+ dp[i-1][1][2],
                                            1 + dp[i-1][2][0], 1 + dp[i-1][2][1], 1+ dp[i-1][2][2]});        }
        else{
            dp[i][0][1] = min({dp[i][0][1], 1 + dp[i-1][0][0], 1 + dp[i-1][1][0], 1 + dp[i-1][2][0]});
            dp[i][0][2] = min({dp[i][0][2], 1 + dp[i-1][0][1], 1 + dp[i-1][1][1], 1 + dp[i-1][2][1]});
        }

        if(words[i].size()>=2){
            if(!isVowel(words[i][0]) && isVowel(words[i][1]) )
                dp[i][1][0] = min( {dp[i][1][0], 2 + dp[i-1][0][0], 2 + dp[i-1][0][1], 2 + dp[i-1][1][0], 2 + dp[i-1][1][1], 2 + dp[i-1][2][0], 2 + dp[i-1][2][1]});
            if(!isVowel(words[i][0]) && !isVowel(words[i][1]) )
                dp[i][1][2] = min( {dp[i][1][2], 2 + dp[i-1][0][0], 2 + dp[i-1][1][0], 2 + dp[i-1][2][0]});
        }
        if(words[i].size()>=3 &&!isVowel(words[i][0]) && !isVowel(words[i][1]) && isVowel(words[i][2])){
            dp[i][2][0] = min( {dp[i][2][0], 3 + dp[i-1][0][0], 3 + dp[i-1][1][0], 3 + dp[i-1][2][0], });
        }
    }
    return min( dp[n-1][0][0], min(dp[n-1][0][1], dp[n-1][0][2])) ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    words = vector<string>(n);

    for(int i=0;i<n;i++){
        cin >> words[i];
        dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = oo;
        dp[i][1][0] = dp[i][1][1] = dp[i][1][2] = oo;
        dp[i][2][0] = dp[i][2][1] = dp[i][2][2] = oo;
    }

    int ans = solve();

    if(ans == oo)
        cout << "*" << "\n";
    else
        cout << ans << "\n";

    return 0;
}
