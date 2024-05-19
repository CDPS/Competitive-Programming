#include <bits/stdc++.h>

using namespace std;

struct node{
    string w;
    int idx1;
    int idx2;
    vector<string> l;

    node(string w, int idx1, int idx2, vector<string> l): w(w), idx1(idx1), idx2(idx2), l(l){}

    bool operator < (const node &a){
        if(w == a.w){
            if(idx1 == a.idx1)
                return idx2 < a.idx2;
            return idx1 < a.idx1;
        }
        return w < a.w;
    }
};

void toUpper(string &a){
    transform(a.begin(), a.end(), a.begin(), ::toupper);
}

void toLower(string &a){
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string w;
    unordered_set<string> f;
    while(w != "::")
        cin >> w, toLower(w), f.insert(w);

    cin.ignore();

    string line;
    int idx1 = 0;

    vector<node> a;
    while(getline(cin, line)){
        toLower(line);
        stringstream ss (line);
        vector<string> l;

        while(ss >> w)
            l.push_back(w);

        for(int i=0;i<l.size();i++){
            if(!f.count(l[i])){
                toUpper(l[i]);
                a.push_back(node(l[i],idx1,i,l));
                toLower(l[i]);
            }
        }
        idx1++;
    }

    sort(a.begin(), a.end());
    for(int i=0;i<a.size();i++){
        int idx = a[i].idx2;
        a[i].l[idx] = a[i].w;

        cout << a[i].l[0];
        for(int j=1;j<a[i].l.size();j++)
            cout <<  " " << a[i].l[j];
        cout << "\n";
    }

    return 0;
}
