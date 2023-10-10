#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int,int>> pq;

int main(){

    int sum, limit;

    cin >> sum >> limit;

    for(int i=1;i<=limit;i++){
        int p = 1;
        for(int j = 0; j < 32; j++){
            if(i & (1 << j)){
                pq.push( make_pair(p,i) );
                break;
            }
            p *= 2;
        }
    }

    vector<int> res;
    while( sum > 0  && !pq.empty()){
        pair<int,int> x = pq.top();
        if(x.first <= sum ){
            sum-= x.first;
            res.push_back(x.second);
        }
        pq.pop();
    }

    if( sum == 0 ){
        cout << res.size() << "\n";
        cout << res[0];
        for(int i=1;i<res.size();i++)
            cout << " " << res[i];
         cout << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    return 0;
}
