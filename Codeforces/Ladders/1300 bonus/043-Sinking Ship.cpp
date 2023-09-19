#include <bits/stdc++.h>

using namespace std;

int main(){


    int n;
    string person, group;

    cin >> n ;

    queue<string> rats;
    queue<string> wc;
    queue<string> man;
    queue<string> cp;

    while(n--){
        cin >> person >> group;

        if(group=="rat")
            rats.push(person);
        if(group == "woman" || group == "child")
            wc.push(person);
        if(group == "man")
            man.push(person);
         if(group == "captain")
            cp.push(person);
    }

    while(!rats.empty()){cout << rats.front() << "\n"; rats.pop();}
    while(!wc.empty()){cout << wc.front() << "\n"; wc.pop();}
    while(!man.empty()){cout << man.front() << "\n"; man.pop();}
    while(!cp.empty()){cout << cp.front() << "\n"; cp.pop();}
    return 0;
}
