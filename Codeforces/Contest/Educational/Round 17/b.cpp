#include <bits/stdc++.h>

using namespace std;


int main(){

    long long usb,ps2,both;

    cin >> usb >> ps2 >> both;

    long m;
    cin >> m;

    long w;
    string s;

    priority_queue<long long, vector<long long> , greater<long long>  > a1;
    priority_queue<long long, vector<long long> , greater<long long> > a2;

    for(long i=0;i<m;i++){
        cin >> w >> s;
         if(s[0]=='U') a1.push(w);
         else a2.push(w);
    }

    long long res=0;
    long long cu=0;

    while( (usb--) && !a1.empty()){ res+=a1.top(); a1.pop(); cu++; }
    while( (ps2--) && !a2.empty()){ res+=a2.top(); a2.pop(); cu++ ;}

    while( both-- ){
        if(a1.empty() && a2.empty())break;

        if(!a1.empty() && !a2.empty()) {
            if(a1.top()< a2.top()){
                res+=a1.top(); a1.pop();
                cu++;
                continue;
            }else{ res+=a2.top(); a2.pop(); cu++; continue;}
        }

        if(a1.empty()){ res+=a2.top();a2.pop();cu++; continue;}
        if(a2.empty()){res+=a1.top();a1.pop();cu++; continue;}
    }

    cout << cu << " " << res << "\n";
    return 0;
}
