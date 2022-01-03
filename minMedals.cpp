#include<iostream>

using  namespace std;

void decreseMedals(int arr[], int* medals, int ind, int n){
    if(ind == 0 ){
        if(arr[ind] > arr[ind+1])
            medals[ind] = medals[ind+1] + 1;
        else 
            medals[ind] = 1;
    }
    else if (ind < n-1){
        if(arr[ind] > arr[ind+1] && arr[ind] > arr[ind-1])
            medals[ind] = max(medals[ind-1], medals[ind+1]) + 1;
        else if (arr[ind-1] < arr[ind] && arr[ind] < arr[ind+1])
            medals[ind] = medals[ind-1] +1;
        else if(arr[ind-1] > arr[ind] && arr[ind] > arr[ind+1])
            medals[ind] = medals[ind+1] + 1;
        else
            medals[ind] = 1;
    }
    else{
        if(arr[ind] < arr[ind-1])
            medals[ind] = 1;
        else
            medals[ind] = medals[ind-1] + 1; 
    }
}

int getMinMedals(int arr[], int n){
    int medals[n];

    for(int i=0;i<n;i++)
        medals[i] = arr[i];

    for(int i=0;i<n;i++){
        decreseMedals(arr, medals, i, n);
    }

    for(int i=n-1;i>=0;i--){
        decreseMedals(arr, medals, i, n);
    }

    int sum = 0;

    for(int i=0;i<n;i++)
        sum += medals[i];

    return sum;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int medals = getMinMedals(arr, n);
    cout << medals << endl;

    return 0;
}