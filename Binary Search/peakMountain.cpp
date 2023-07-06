// LeetCode : 852 Peak Index in a Mountain Array
#include<iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int size) {
    int s=0;
    int e=size -1;

    int mid=s+(e-s)/2;

    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return mid;
}

int main(){
    int mountainArray[6] = {1,3,5,6,3,1};
    int peak = peakIndexInMountainArray(mountainArray,6);

    cout<<"The peak of the mountain array is Index "<<peak<<endl;

    return 0;
}