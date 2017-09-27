#include <bits/stdc++.h>

using namespace std;

int main(){

    long n,m;
    cin >> n >> m;
    long pos = 1,next;
    long long res=0;

    for(int i=0;i<m;i++){
        cin >> next;
        long r1,r2;
        if(next >=pos){
            r1 = next - pos;
            pos=next;
        }else {
            r1 = (n-pos) + next;
            pos =next;
        }
        res+= r1;
    }

    cout << res << "\n";
    return 0;
}
