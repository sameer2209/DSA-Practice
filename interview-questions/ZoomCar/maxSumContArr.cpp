/*
https://leetcode.com/problems/maximum-subarray/solution/ 
Approach: kadane's Algorithm
*/

#include<iostream>

using namespace std;

int findMaxContSum(int arr[], int n){

    int currSum = arr[0], maxSum = arr[0];

    for(int i=1;i<n;i++){
        if(currSum + arr[i] > arr[i]){
            currSum += arr[i];
        }
        else{
            currSum = arr[i];
        }

        if(currSum > maxSum)
            maxSum = currSum;
    }

    if(currSum > maxSum)
        maxSum = currSum;

    return maxSum;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << findMaxContSum(arr, n) << endl;

    return 0;
}