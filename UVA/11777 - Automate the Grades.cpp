#include <bits/stdc++.h>

using namespace std;

int a[7];

char getGrade(int x){
    if(x>=90) return 'A';
    if(x>=80) return 'B';
    if(x>=70) return 'C';
    if(x>=60) return 'D';
    return 'F';
}

int main(){

    int t, caseno = 1;

    cin >> t;

    while(t--){

        for(int i=0;i<7;i++) cin >> a[i];

        sort(a+4, a + 7);

        int ans = a[0] + a[1] + a[2] + a[3] + (  (a[5] + a[6])/2 );

        cout << "Case " << caseno++ << ": " << getGrade(ans) << "\n";
    }

    return 0;
}
