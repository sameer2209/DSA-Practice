/*
DSA Question asled in first technical round of SmartCoin financial.
Question link: https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

pair<int, int> find_pair(int arr[], int n, int x){
    pair<int, int> p;
    int left = 0, right = n-1;
    int min_diff = INT_MAX;

    while(left < right){
        int sum = arr[left] + arr[right];
        int diff = sum - x;
        int absdiff = abs(diff);

        if(absdiff < min_diff){
            min_diff = absdiff;
            p = pair<int, int>(arr[left], arr[right]);
        }

        if(diff >= 0)
            right--;
        else
            left++;
    }

    return p;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int x;
    cin >> x;

    pair<int, int> p = find_pair(arr, n, x);
    cout << p.first << " " << p.second << endl;
    return 0;
}