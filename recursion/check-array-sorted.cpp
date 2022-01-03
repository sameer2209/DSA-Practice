#include<iostream>

using namespace std;

int isSorted(int arr[], int start, int end){
    if(start + 1 == end){
        if(arr[start] <= arr[end])
            return 1;
        else 
            return 2;
    }

    if(start == end)
        return 1;

    int sortOrder = arr[start] <= arr[start+1] ? 1 : 2;

    if(sortOrder == isSorted(arr, start+1, end))
        return sortOrder;
    else
        return 0;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    if(isSorted(arr, 0, n-1) >= 1)
        cout << "array is sorted" << endl;
    else
        cout << "array not sorted" << endl;
}