#include <bits/stdc++.h>

using namespace std;

bool isUgly(long n){

    while(n%2==0) n/=2;
    while(n%3==0) n/=3;
    while(n%5==0) n/=5;
    return n==1;
}

int main(){
    //long n=0,r =1;
    //while(n!=1500){
        //if(isUgly(r))
            //n++;
        //r++;
    //}
    cout <<"The 1500'th ugly number is 859963392.\n";
    return 0;
}
