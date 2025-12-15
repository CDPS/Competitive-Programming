#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

string get(vector<int> &a){
    string ans = "";
    for(int i=0, j=0;i<n;i++){
        if( j>= a.size() ||  i != a[j] )
            ans+= s[i];
        else j++;
    }
    return ans;
}

bool check(vector<int> &a){

    if(a.size() <= 1) return true;
    for(int i=1;i<a.size();i++)
        if(s[a[i]]< s[a[i-1]])
            return false;
    return true;
}

bool isPalindrom(vector<int> &a){
    string r = get(a),  rp = r;
    reverse(rp.begin(), rp.end());
    return r == rp;
}

void solve(){

    cin >> n >> s;

    vector<int> ans;
    if(isPalindrom(ans)){
        cout << 0 << "\n" << "\n";
        return;
    }

    for(int mask=1; mask < (1<<n) -1; mask++ ){

        vector<int> temp;
        for(int i=0;i<n;i++)
            if(( mask&(1<<i) )!=0 )
                temp.push_back(i);

        if(check(temp) && isPalindrom(temp)){
            ans = temp;
            break;
        }
    }


    if(ans.size()==0){
        cout << -1 << "\n";
        return;
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i]  + 1 << " ";
    cout << "\n";
}
int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
         solve();
    return 0;
}

