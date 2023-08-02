// CodeStudio : First and Last Position of an Element in Sorted Array

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int k){
    int s=0, e=n-1;
    int mid = s+(e-s)/2;
    int ans =-1;

    while(s<=e){

        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(k>arr[mid]){
            s=mid+1;
        }
        else if (k<arr[mid]){
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int k){
    int s=0, e=n-1;
    int mid = s+(e-s)/2;
    int ans =-1;

    while(s<=e){

        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(k>arr[mid]){
            s=mid+1;
        }
        else if (k<arr[mid]){
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){

    int num[8]={0,1,2,3,3,3,5,7};
    int FirstOcc = firstOcc(num, 8, 3);
    int LastOcc = lastOcc(num, 8, 3);

    cout<<"First Occurence of 3 is at Index "<<FirstOcc<<endl;
    cout<<"Last Occurence of 3 is at Index "<<LastOcc<<endl;

    return 0;
}