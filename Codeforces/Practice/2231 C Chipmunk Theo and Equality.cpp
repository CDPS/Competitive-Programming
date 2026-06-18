#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){


    cin >> n;

    vector<pair<int,int> > a;
    for(int i=0; i < n; i++){
        cin >> x;
        if(x == 1){
            a.push_back({1 , 0});
            a.push_back({2 , 1});
        }else{
            int cost = 0;
            while(x!=1){
                 a.push_back({x , cost++});
                 if(x%2) x++;
                 else x/=2;
            }
            a.push_back({x, cost});
        }
    }

    sort(a.begin(), a.end());

    int ans  = 1e9;
    int curr_elements = 1;
    int curr_cost = a[0].second;
    for(int i=1; i < a.size(); i++){

        if(a[i].first != a[i-1].first ){

            if(curr_elements == n)
                ans = min(ans, curr_cost);
            
            curr_elements = 1;
            curr_cost = a[i].second;
        }else{

            curr_elements++;
            curr_cost += a[i].second;
        }
    }

     if(curr_elements == n)
        ans = min(ans, curr_cost);

    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}