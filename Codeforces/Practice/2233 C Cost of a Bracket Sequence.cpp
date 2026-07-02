#include <bits/stdc++.h>

using namespace std;

int t, n, k;

string s;

int calc(string mask){

    int curr_open = 0, curr = 0;
    for(int i=0; i <n; i++){
        if(mask[i] == '1') continue;
        if(s[i] == '(') curr_open++;
        if(s[i] == ')' && curr_open > 0){\
            curr++;
            curr_open--;
        }
    }
    return curr* 2;
}

string solve(){

    cin >> n >> k >> s;

    vector<int> open, close;
    for(int i=0; i < n; i++){
        if(s[i] == '(') open.push_back(i);
        if(s[i] == ')') close.push_back(i);
    }

    reverse(close.begin(), close.end());

    string ans_mask(n, '0');
    int ans = 1e9; 
    for(int x=0; x<= min(k, (int)open.size()); x++){
        
        string mask(n, '0');
        int y = min(k-x, (int)close.size());

        for (int i = 0; i < x; i++) mask[open[i]] = '1';
        for (int j = 0; j < y; j++) mask[close[j]] = '1';
   
        int curr = calc(mask);
        if (curr < ans) 
            ans = curr, ans_mask = mask;
    }
    
    return ans_mask;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    
    return 0;
}