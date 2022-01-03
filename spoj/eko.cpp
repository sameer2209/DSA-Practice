// SPOJ question https://www.spoj.com/problems/EKO/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid){
    int totalWoodCut = 0;

    for(int i=0;i<n;i++){
        int woodCut = arr[i] - mid > 0 ? arr[i] - mid : 0;
        if(woodCut > 0){
            if(totalWoodCut + woodCut >= k)
                return true;
            else
                totalWoodCut += (arr[i] - mid);
        }
    }

    return false;
}

int findMaxHeight(int arr[], int n, int k){
    int left = 0;
    int right = -1;
    int ans = -1;

    for(int i=0;i<n;i++)
        right = max(right, arr[i]);

    while(left <= right){
        int mid = (left+right)/2;

        if(isPossible(arr, n, k, mid)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << findMaxHeight(arr, n, k) << endl;
    return 0;
}