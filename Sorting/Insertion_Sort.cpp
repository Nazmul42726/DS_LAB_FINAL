#include<iostream>
using namespace std;

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertion_sort(int arr[], int size){
    for(int i=1; i<size; i++){
        int j,key=arr[i];
        for(j=i-1; j>=0 && arr[j]>key; j--){
            swap(&arr[j],&arr[j+1]);
        }
        arr[j+1]=key;
    }
}