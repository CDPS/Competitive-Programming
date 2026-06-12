#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool solve(){

    cin >> n >> s;

    vector<bool> is_wall(n, false);

    bool check = false;
    for(int i=0; i < n; i++){
        if(s[i] == '1' && i ==  0) is_wall[i] = true;
        if(s[i] == '1' && i ==n-1) is_wall[i] = true;
        if(i < n-1 && s[i] == '1' && s[i+1] == '1' ){
            while(s[i] == '1')
                is_wall[i++] = true;
            i--;
        }
    }

    int last_wall = -1;
    for(int i=0; i < n ; i++){
        if(is_wall[i]){

            if(last_wall != -1 && i - last_wall > 1 ){

                int  zero_count  = 0;
                bool has_00 = 0;

                for (int j = last_wall + 1; j < i; j++) {
                    if (s[j] == '0') {
                        zero_count++;

                        if (j < i - 1 && s[j+1] == '0') {
                            has_00 = true;
                        }
                    }
                }

                if (!has_00 && zero_count % 2)
                    return false;
            }

            last_wall  = i;
        }
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
