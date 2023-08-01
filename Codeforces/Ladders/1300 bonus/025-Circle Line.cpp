#include <bits/stdc++.h>

using namespace std;

int a[100];

int getDist(int x, int y, bool take){
    int ans =0;
    if(x==y && take)
        return ans;
    for(int i=x;i<=y;i++){
        ans+= a[i];
    }
    return ans;
}

int main(){

    int n,x,y;

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> x >> y;

    if(x>y)
        swap(x,y);

    x--; y-=2;
    int ans1 = getDist(x,y, true);
    int ans2 = getDist(y+1, n-1, false) + getDist(0, x-1, false);

    cout << min(ans1, ans2) << "\n";
    return 0;
}
