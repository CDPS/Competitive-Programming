#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, r, idx;
    node(int l, int r, int idx): l(l),r(r), idx(idx){}
    bool operator<(const node &a) const {
        return l < a.l;
    }
};

int ans[200000];

int main(){

    int n,x, y;
    cin >> n;

    vector<node> v;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        v.push_back(node(x,y,i));
    }
    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int rooms = 0;
    for(int i=0;i<n;i++){
        if(pq.empty() || pq.top().first >= v[i].l){
            rooms++;
            ans[v[i].idx] = rooms;
            pq.push({v[i].r, rooms});
        }else{
            int room = pq.top().second; pq.pop();
            ans[v[i].idx] = room;
            pq.push({ v[i].r, room });
        }
    }

    cout << rooms << "\n";
    for(int i=0;i<n;i++)
        cout << ans[i] << " \n"[i==n-1];

    return 0;
}
