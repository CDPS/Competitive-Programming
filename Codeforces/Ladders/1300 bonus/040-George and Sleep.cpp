#include <bits/stdc++.h>

using namespace std;

int main(){

    string a, b;

    cin >> a;
    cin >> b;

    int hours_a = (a[0]-'0')*10 + (a[1]-'0');
    int minutes_a = (a[3]-'0')*10 + (a[4]-'0');

    int hours_b = (b[0]-'0')*10 + (b[1]-'0');
    int minutes_b = (b[3]-'0')*10 + (b[4]-'0');

    int minutes = 0;
    if (minutes_a-minutes_b < 0 )
    	minutes = minutes_a-minutes_b + 60, hours_a--;
    else
        minutes = minutes_a-minutes_b;

    int hours = ( hours_a-hours_b < 0)? hours_a-hours_b + 24 :hours_a-hours_b;

    cout << setfill('0') << setw(2) <<  hours << ":" << setfill('0') << setw(2) << minutes;
    return 0;
}
