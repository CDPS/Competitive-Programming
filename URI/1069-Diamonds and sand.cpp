#include <bits/stdc++.h>

using namespace std;


int main(){


    int t;
    cin >> t;

    while(t--){

        string line;
        cin >> line;

        stack<char> s;

        long res=0;
        for(long i=0;i<line.size();i++){

            if(line[i]=='<')
                s.push(line[i]);

            if(line[i]=='>'){
                if(!s.empty()){
                    s.pop();
                    res++;
                }
            }
        }

        printf("%ld\n",res);
    }

    return 0;
}
