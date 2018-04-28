#include <iostream>
#include "header.h"

void Merger(int arr[],int lo, long int  mi, long int hi){
    int *temp = new int[hi-lo+1];//temporary merger array
    long int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    long int k = 0;//k is for the temporary array
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //rest elements of left-half
    while(i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while(j <= hi)
        temp[k++] = arr[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];

    delete []temp;
}
void MergeSortHelper(int arr[], int lo, long int hi){
    long int mid;
    if(lo < hi){
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid+1, hi);
        Merger(arr, lo, mid, hi);
    }
}
void merge_sort(int arr[],int start, long int arr_size){
    MergeSortHelper(arr,start,arr_size-1);
}
