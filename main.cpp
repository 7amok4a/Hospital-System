//Athour : 7amok4a
//Return Dark ^_^ &_&
// parell programming
#include <bits/stdc++.h>
using namespace std;
int const row = 20 , col = 5 ;
string arr [row][col] ;
int SizeofDepartment [row] = {0};
void Freearrays () {
    memset(SizeofDepartment , 0 ,sizeof (SizeofDepartment)) ;
}
bool TestInput(int n) {
    return n >= 1 and n <= 4;
}
int InputProcess (int n) {
    while (!TestInput(n)) {
        cout << "Invalied Input , Please Try Again\n" ;
        cin >> n ;
    }
    return  n ;
}
void Add (int index , string &name , int statue) {
    -- index ;
    if (SizeofDepartment[index] <= 4){
            if (statue == 1) {
                for (int i = SizeofDepartment[index] ; i > 0 ; --i) {
                    arr[index][i] = arr[index][i-1] ;
                }
                arr[index][0] = (name + " urgent") ;
                SizeofDepartment[index]++ ;
            }
            else {
                arr[index][SizeofDepartment[index]++] = (name + " regular") ;
            }
    }
    else {
        cout << "Sorry Compelete!!!\n" ;
    }
}
void Print () {
    for (int i = 0 ; i < 20 ; ++i) {
        if (SizeofDepartment[i] > 0 ) {
            cout << "There are " << SizeofDepartment[i] << " in : " << i + 1 << "\n" ;
            for (int ii = 0 ; ii < SizeofDepartment[i] ; ++ii) {
                cout << arr[i][ii] << "\n" ;
            }
        }
        else {
            continue;
        }
    }
}
void Getnext (int index) {
    --index ;
    if (SizeofDepartment[index] == 0) {
        cout << "No Paients\n" ;
    }
    else {
        for (auto &i : arr[index][0]) {
            cout << i ;
            if ( i == ' ' )
                break ;
        }
    }
    for (int i = 0 ; i < SizeofDepartment[index] - 1  ; ++i) {
        arr[index][i] = arr[index][i + 1] ;
    }
    --SizeofDepartment[index] ; 
}
void Progress () {
    int n ;
    Freearrays() ;
    while (cin >> n) {
        int result = InputProcess(n);
        if (result == 1) {
            cout << "Enter specialization , name , statues : " ;
            int specialization = 0 ;
            string name ;
            int statue = 0 ;
            cin >> specialization >> name >> statue ;
            Add(specialization , name , statue) ;
        }
        else if (result == 2) {
            Print() ;
        }
        else if (result == 3) {
            cout << "Enter specialization : " ;
            int specialization = 0 ;    cin >> specialization ;
            Getnext(specialization) ;
            cout << "\n" ;
        }
        else {
            return;
        }
        cout << "---------------------------------------------------------\n" ;
    }
}
int main() {
    cout << "Enter your choice\n" ;
    cout << "1) Add new patient\n" ;
    cout << "2) Print all patients\n" ;
    cout << "3) Get next paient\n" ;
    cout << "4) Exit\n" ;
    Progress() ;
    return 0;
}
