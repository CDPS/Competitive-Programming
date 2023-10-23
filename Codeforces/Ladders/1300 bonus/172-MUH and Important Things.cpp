#include <stdc++.h>

using namespace std;

map<int, vector<int> > mp;

int main(){

    int n,x;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        mp[x].push_back(i+1);
    }

    map<int, vector<int> >::reverse_iterator it;

    int r = 0;
    for(it = mp.rbegin(); it!=mp.rend();it++){
        if(it->second.size()>1){
            r += it->second.size();
        }
    }

    if(r >= 3){

        vector<int> res;

        it = mp.rbegin();
        for(; it!=mp.rend();it++){
            if(it->second.size()>1){
                vector<int> aux = it->second;
                next_permutation(aux.begin(), aux.end());
                it->second = aux;
                res.insert (res.end(),aux.begin(),aux.end());
            }else{
                res.push_back(it->second[0]);
            }
        }

    }
    else{
        cout  << "NO" << "\n";
    }
    return 0;
}
