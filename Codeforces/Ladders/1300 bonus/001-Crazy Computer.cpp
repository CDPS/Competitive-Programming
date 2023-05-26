#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n, c;

    cin >> n >> c;

    for(int i=0;i<n;i++)
        cin >> a[i];

    int answer = 1;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]<=c){
            answer++;
        }
        else{
            answer=1;
        }
    }
    cout << answer;
    return 0;
}
