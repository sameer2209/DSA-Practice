/*
DSA problem asked in the first technical round of SmartCoin Financials.
Rain water trapping problem was asked https://www.geeksforgeeks.org/trapping-rain-water/
Given solution is O(n) time complexity and O(1) space complexity
*/

#include<iostream>

using namespace std;

int calc_water(int arr[], int n){
    int water = 0;
    int left_max = 0, right_max = 0;
    int left = 0, right = n-1;

    while(left<=right){
        if(arr[left] <= arr[right]){
            if(left_max >= arr[left])
                water += left_max - arr[left];
            else
                left_max = arr[left];    
            left++;
        }
        else{
            if(right_max >= arr[right])
                water += right_max - arr[right];
            else
                right_max = arr[right];
            right--;
        }
    }

    return water;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << calc_water(arr, n) << endl;
    return 0;
}