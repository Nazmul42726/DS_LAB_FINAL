#include<iostream>
using namespace std;

//**Alert: you have to call the merge_sort function like:
//         merge_sort(array_name, first_index, last_index)
//**Remember:when we are sorting the whole array:
//        first_index=0 and last_index=arrays_size-1

void merge(int arr[], int left, int mid, int right){
    int size1=mid-left+1;
    int size2=right-mid;

    int leftSegment[size1],rightSegment[size2];
    for(int i=0; i<size1; i++){
        leftSegment[i]=arr[i+left];
    }
    for(int i=0; i<size2; i++){
        rightSegment[i]=arr[i+mid+1];
    }
    int i=0,j=0,k=left;
    while(i<size1 && j<size2){
        if(leftSegment[i]<rightSegment[j]){
            arr[k]=leftSegment[i];
            i++;
        }
        else{
            arr[k]=rightSegment[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[k]=leftSegment[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k]=rightSegment[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    // else return;
}