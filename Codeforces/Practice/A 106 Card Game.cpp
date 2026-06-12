#include <bits/stdc++.h>

using namespace std;

int t =1;

string trump, card1, card2;

map<char, int> score = {
    { '6', 6  },
    { '7', 7  },
    { '8', 8  },
    { '9', 9  },
    { 'T', 10 },
    { 'J', 11 },
    { 'Q', 12 },
    { 'K', 13 },
    { 'A', 15 },
};

bool solve(){

    cin >> trump >> card1 >> card2;

    if(card1[1] == card2[1])
        return score[card1[0]] > score[card2[0]];

    if(card1[1] == trump[0] && card2[1] != trump[0] )
        return true;

    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << (solve()? "YES" : "NO" )  << "\n";

    return 0;
}


