#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int stones[2000];
set<int> setStones;
int n;

bool isValid(int val, int k){
    return val >= k && k >0;
}

bool bfs(int in, int kp){

    queue<node> q;

    q.push(make_pair(in,kp));

    while(!q.empty()){
        node u = q.front();
        q.pop();

        int val = u.first;
        int k   = u.second;
        //cout << val << " " << k << "\n";
        if(val==1 && k==1)
            return true;
        set<int>::iterator it = setStones.find(val - k);
        if(it != setStones.end()){
           if(isValid(val-k,k))
            q.push(make_pair(val-k,k));
           if(isValid(val-k,k-1))
            q.push(make_pair(val-k,k-1));
           if(isValid(val-k,k+1))
            q.push(make_pair(val-k,k+1));
        }
    }
    return false;
}

int main(){

    cin >> n;

    for(int i=0;i< n;i++){
        cin >> stones[i];
        setStones.insert(stones[i]);
    }

    bool ans = false;
    for(int i=n-2; i>= 0; i--){
        ans = bfs( stones[n-1], stones[n-1]-stones[i]);
        if(ans) break;
    }
    cout << (ans? "true" : "false") << "\n";
    return 0;
}
