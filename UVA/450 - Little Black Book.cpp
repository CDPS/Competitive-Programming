#include <bits/stdc++.h>

using namespace std;

struct node{
    string title;
    string name;
    string lastName;
    string homeAddress;
    string department;
    string homePhone;
    string workPhone;
    string campusBox;

    node(string title,
         string name,
         string lastName,
         string homeAddress,
         string department,
         string homePhone,
         string workPhone,
         string campusBox): title(title), name(name), lastName(lastName),
                            homeAddress(homeAddress), department(department),
                            homePhone(homePhone), workPhone(workPhone), campusBox(campusBox){}

    bool operator < (const node & a){
        return lastName < a.lastName;
    }
};

int main(){

    int t;
    cin >> t;
    cin.ignore();

    string line, department, title, name,lastName,homeAddress,homePhone,workPhone, campusBox;

    vector<node> a;
    while(t--){

        getline(cin, department);

        while(true){
            getline(cin, line);

            if(line == "" ) break;

            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, name, ',');
            getline(ss, lastName, ',');
            getline(ss, homeAddress, ',');
            getline(ss, homePhone, ',');
            getline(ss, workPhone, ',');
            getline(ss, campusBox, ',');

            a.push_back(node(title, name, lastName, homeAddress, department, homePhone, workPhone, campusBox));
        }
    }

    sort(a.begin(), a.end());

    for(int i=0;i<a.size();i++){
        cout << "----------------------------------------" << "\n";
        cout << a[i].title << " " << a[i].name << " " << a[i].lastName << "\n";
        cout << a[i].homeAddress << "\n";
        cout << "Department: " << a[i].department << "\n";
        cout << "Home Phone: " << a[i].homePhone << "\n";
        cout << "Work Phone: " << a[i].workPhone << "\n";
        cout << "Campus Box: " << a[i].campusBox << "\n";
    }

    return 0;
}
