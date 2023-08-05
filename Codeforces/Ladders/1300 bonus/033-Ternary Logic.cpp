#include <bits/stdc++.h>

using namespace std;

int invert[3][3] = {  {0,2,1}, {1,0,2}, {2,1,0}  };

long long getTernaryNotation(int n){
    long long answer = 0;
    long long pow = 1;
    while(n>0){
        long long d = n%3;
        n/=3;
        answer+= d * pow;
        pow*=10;
    }
    return answer;
}

long long getB(long long c, long long a){

    long long answer = 0;
    long long pow = 1;
    while(c>0 || a>0){

        long long d1 = c%10;
        long long d2 = a%10;
        c/=10;
        a/=10;
        int d = invert[d1][d2];
        answer+= d * pow;
        pow*=10;
    }
    return answer;
}

long long getTenNotation(long long ternary){
    long long answer = 0;
    long long pow = 1;
    while(ternary>0){
        long long d = ternary%10;
        ternary/=10;
        answer+= d * pow;
        pow*=3;
    }
    return answer;
}

int main(){

    int a, c;
    cin >> a >> c;

    long long ternaryA = getTernaryNotation(a);
    long long ternaryC = getTernaryNotation(c);
    long long ternaryB = getB(ternaryC, ternaryA);

    cout << getTenNotation(ternaryB) << "\n";
    return 0;
}
