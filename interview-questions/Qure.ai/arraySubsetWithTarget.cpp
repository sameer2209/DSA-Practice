#include<iostream>

using namespace std;

bool isSubsetSumEqualsTarget(int arr[], int start, int n ,int target, int sum){
    if(start == n)
        return false;

    if(sum == target)
        return true;

    if(isSubsetSumEqualsTarget(arr, start+1, n, target, sum+arr[start]) || isSubsetSumEqualsTarget(arr, start+1, n, target, sum))
        return true;
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int target;
    cin >> target;

    if(isSubsetSumEqualsTarget(arr, 0, n ,target, 0))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}