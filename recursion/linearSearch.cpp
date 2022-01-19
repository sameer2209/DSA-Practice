#include<iostream>

using namespace std;

bool isPresent(int arr[], int n, int target){
    if(n == 0)
        return false;

    if(arr[0] == target)
        return true;
    
    return isPresent(arr+1, n-1, target);
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin >> arr[i];

    int target;
    cin >> target;

    if(isPresent(arr, n, target))
        cout << "element found" << endl;
    else
        cout << "element not found" << endl;
    return 0;
}