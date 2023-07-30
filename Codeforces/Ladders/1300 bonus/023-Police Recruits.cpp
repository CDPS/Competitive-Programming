#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,c=0,x,p=0;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        if(x<0){
            if(p!=0){
                p--;
            }
            else{
                c++;
            }
        }else{
            p+=x;
        }
    }
    cout << c << "\n";
    return 0;
}

