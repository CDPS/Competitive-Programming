#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

int main() {

    int ans = 0;
    string s;
    cin >> s;
    map<int, int> mp;
    priority_queue<int> pq;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]]++;

    map<int, int>::iterator it;
    it = mp.begin();

    while(it != mp.end()) {

        ans += (*it).second;
        pq.push((*it).second);
        it++;
    }

    ans -= pq.top();
    pq.pop();
    ans -= pq.top();
    pq.pop();

    if(ans <= 0)
        cout << 0 << endline;
    else
        cout << ans << endline;

    return 0;
}
