#include <bits/stdc++.h>

using namespace std;

struct node{
    int x;
    bool c;
    node(int x, bool c): x(x), c(c){}
    bool operator < (const node &a){
        return x > a.x;
    }
};

int main(){

    int t,n,x;
    cin >> t;

    while(t--){

        cin >> n;

        vector<node> a;

        for(int i=0;i<n;i++)
            cin >> x, a.push_back(node( abs(x), x > 0 ));

        sort(a.begin(), a.end());

        bool color = true;
        int ans1=0, ans2=0;
        for(int i=0;i< n;i++)
            if(a[i].c == color)
                ans1++, color = !color;

        color = false;
        for(int i=0;i< n;i++)
            if(a[i].c == color)
                ans2++, color = !color;

        cout << max(ans1, ans2) << "\n";
    }

    return 0;
}
