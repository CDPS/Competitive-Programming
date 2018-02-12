#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
int n,m,x;

int BinarySearch(long long x){
    int l = 0, h = n,m;
    while(l< h){
         m = l + ( (h-l)/2 );
        if( v[m] < x)
             h = m;
        else l = m +1;
    }
    return l;
}

int main(){

    scanf("%d",&n);
    set<long long> st;
    for(int i=0;i<n;i++) cin >> x, st.insert(x);

    set<long long>::iterator it;

    n = st.size();
    int j = n-1;
    v = vector<long long>(n);
    for(it=st.begin();it!=st.end();it++,j--) v[j] = *it;
    v.push_back(0);

    cin >> m;
    while(m--){
        cin >> x;
        int idx = BinarySearch(x);
        if(v[idx-1]!=x)
            cout << idx+1 << "\n";
        else
            cout << idx << "\n";
    }
    return 0;
}
