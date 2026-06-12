#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;

int t = 1, n, k;

vector< pair<int,int> > factorize (int x) {

	vector< pair<int,int> > ans;

	for (int i = 2; i * i <= x; i++) {
		int acc = 0;
		while (x % i == 0)
			acc++, x /= i;
        if( acc %k != 0)
            ans.push_back({i, acc%k});
	}

	if (x > 1)
        ans.push_back({x, 1 % k});

    return ans;
}

int x;

ll solve(){

    cin >> n >> k;

    ll ans = 0;
    map< vector< pair<int,int> >, int >  mp;
    for(int i=0; i < n; i++){

        cin >> x;

        auto factors = factorize(x);

        vector< pair<int,int> > fp;
        for(int i = 0; i < factors.size(); i++)
            fp.push_back({ factors[i].f, k - factors[i].s } );

        ans += mp[ fp ];
        mp[factors]++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
