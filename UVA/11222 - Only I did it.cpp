#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n,x, caseno = 1;
    cin >> t;

    while(t--){
        set<int> a,b,c;

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x, a.insert(x);

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x, b.insert(x);

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x, c.insert(x);

        vector<int> resa, resb, resc;
        for(auto i=a.begin(); i!=a.end();i++)
            if( b.find(*i) == b.end() && c.find(*i) == c.end() )
                resa.push_back(*i);

        for(auto i=b.begin(); i!=b.end();i++)
            if( a.find(*i) == a.end() && c.find(*i) == c.end() )
                resb.push_back(*i);

        for(auto i=c.begin(); i!=c.end();i++)
            if( b.find(*i) == b.end() && a.find(*i) == a.end() )
                resc.push_back(*i);

        int targetSize = max( resa.size(), max(resb.size(),resc.size()));

        cout << "Case #" << caseno++ << ":" << "\n";
        if(resa.size()==targetSize){
            cout << 1 << " " << targetSize;
            for(int i=0;i<resa.size();i++)
                cout << " " << resa[i];
            cout << "\n";
        }

        if(resb.size()==targetSize){
            cout << 2 << " " << targetSize;
            for(int i=0;i<resb.size();i++)
                cout << " " << resb[i];
            cout << "\n";
        }

        if(resc.size()==targetSize){
            cout << 3 << " " << targetSize;
            for(int i=0;i<resc.size();i++)
                cout << " " << resc[i];
            cout << "\n";
        }
    }
    return 0;
}
