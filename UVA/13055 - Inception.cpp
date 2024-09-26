#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    string op, name;
    stack<string> s;

    cin >> n;
    while(n--){
        cin >> op;
        if(op[0]== 'S')
            cin >> name, s.push(name);
        if(op[0]== 'T' && !s.empty())
            cout << s.top() << "\n";
        if(op[0]== 'T' && s.empty())
            cout << "Not in a dream" << "\n";
        if(op[0]== 'K' && !s.empty())
            s.pop();
    }
    return 0;
}
