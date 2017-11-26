#include <bits/stdc++.h>

using namespace std;

//On bits on bitmask
long bits(long i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

void allStringToLower(string a){
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}

int a[3]; //contains sides length of a triangle
          //the sides MUST be positives
bool isValidTriangule(){
    sort(a,a+3); //sort
    if( (a[0]+a[1] > a[2]) && (a[0]+a[2]>a[1]) && (a[1]+a[2]>a[0])){
        return true;
    return false;
}

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){

}
