#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool solve(){

    cin >> n >> s;

    for(int i=1;i <n ;i++){

        int target = 0;
        for(int j=0;j < i; j++)
            target+= s[j]-'0';

        for(int j= i, curr = 0; j < n ; j++){

            if(curr == target && curr + s[j]-'0' > target)
                curr =  s[j]-'0' ;
            else if(curr < target && curr + s[j]-'0' > target )
                break;
            else
                 curr +=  s[j]-'0' ;

            if(j == n-1 && curr == target) return true;
        }

    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout << ( solve()? "YES" : "NO" ) << "\n";
    return 0;
}
