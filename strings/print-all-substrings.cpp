#include<iostream>
#include<string>
using namespace std;

void printAllSubstrings(string str){
    int n = str.size();

    for(int i=1; i<=n; i++){
        for(int j=0; j<= n-i; j++){
            cout << str.substr(j, i) << endl;
        }
    }
}

int main(){
    string str;
    cin >> str;

    printAllSubstrings(str);
}