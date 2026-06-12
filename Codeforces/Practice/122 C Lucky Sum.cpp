#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1;

vector<ll> l = {4, 7};
ll pow4 = 40, pow7=70;

ll low, high;

void precalc(){

    vector<ll> prev = l;
    for(int i=2;i<=10;i++){
        vector<ll> curr;
        for(int j=0;j<prev.size();j++){
            curr.push_back(pow4 + prev[j]);
            curr.push_back(pow7 + prev[j]);
        }
        l.insert(l.end(), curr.begin(), curr.end());

        prev = curr;
        pow4*=10; pow7*=10;
    }
    sort(l.begin(), l.end());
}

ll next_lucky(int x){
    return *lower_bound(l.begin(), l.end(), x);
}

ll solve(){

    cin >> low >> high;

    ll ans = 0;
    ll lucky_h = next_lucky(high);
    while(true){

        ll lucky_l = next_lucky(low);

        if(lucky_h == lucky_l){
            ans+= (high-low+1)*lucky_h;
            break;
        }

        ans+= (lucky_l-low +1)*lucky_l;
        low= lucky_l  + 1;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    precalc();

    while(t--)
        cout << solve() << "\n";

    return 0;
}
