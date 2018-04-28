#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include "header.h"

void PrintArray(int A[], long int size)
  {
    long int i;
    for (i=0; i < size; i++)
        std::cout<<A[i]<<" ";
    std::cout<<std::endl;;
  }

bool isSorted(int a[], long int end)
{
	for(long int i=0; i<end; i++)
  {
		if(a[i] > a[i+1]) return false;
	}
	return true;
}

long int Count(int arr[])
{
  long int i = 0;
  while(arr[i]) i++;
  return i;
}


int main(int argc, char const *argv[]) {
  //START PROBNYCH SORTOWAN ZE STWIERDZENIEM POPRAWNOSCI DZIALANIA
    srand(time(NULL));
    int *arr1 = new int[1000000];
    int *arr2 = new int[1000000];
    int *arr3 = new int[1000000];

    for(long int i=0;i<1000000;i++)
    {
      arr1[i] = arr2[i] = arr3[i] = rand()%100000+1;
    }
    long int arr_size = Count(arr1);
    auto start_MERGE = std::chrono::system_clock::now();
    merge_sort(arr1,0,arr_size);
    auto end_MERGE = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds_MERGE = end_MERGE-start_MERGE;
    std::cout<< "MERGE: " << elapsed_seconds_MERGE.count() <<std::endl;

    if(isSorted(arr1,arr_size-1)==true) std::cout<<"Posortowano poprawnie"<<std::endl;
    else std::cout<<"Cos poszlo nie tak :("<<std::endl;

    auto start_QUICK = std::chrono::system_clock::now();
    quicksort(arr2,0,arr_size-1,0);
    auto end_QUICK = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds_QUICK = end_QUICK-start_QUICK;
    std::cout<< "QUICK: " << elapsed_seconds_QUICK.count() <<std::endl;
    //PrintArray(arr2,arr_size);
    //PrintArray(arr1,arr_size);
    if(isSorted(arr2,arr_size-1)==true) std::cout<<"Posortowano poprawnie"<<std::endl;
    else std::cout<<"Cos poszlo nie tak :("<<std::endl;

    auto start_INTRO = std::chrono::system_clock::now();
    introspective_Sort(arr3,arr_size);
    auto end_INTRO = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds_INTRO = end_INTRO-start_INTRO;
    std::cout<< "INTRO: " << elapsed_seconds_INTRO.count() <<std::endl;
    if(isSorted(arr3,arr_size-1)==true) std::cout<<"Posortowano poprawnie"<<std::endl;
    else std::cout<<"Cos poszlo nie tak :("<<std::endl;
    //PrintArray(arr2,arr_size);
    //PrintArray(arr3,arr_size);
    TEST();
  return 0;
}
