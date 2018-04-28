#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include <vector>
#include "header.h"

void Show_Solution(std::vector<double>solution)
{
    int tab[] = {10000,50000,100000,500000,1000000};
    for(int i=0;i<5;i++) std::cout<<tab[i]<<" -- "<<solution[i]<<" s "<<std::endl;
}

std::vector<double> main_modul(int type, int level)
{
long tabX[]={10000,50000,100000,500000,1000000}; //Wartosci osi X
std::vector<double>vector_TEMP;
std::chrono::duration<double> elapsed_seconds;
int * tab_temp = new int[1000000];
for(int k=0;k<5;k++)
{
elapsed_seconds = std::chrono::seconds::zero();
for(int j=1;j<=100;j++)
{
  long arr_size = tabX[k];
  for(int i=0;i<tabX[k];i++)
    {
      tab_temp[i] = rand()%100000+1;
      //std::cout<<i<<std::endl;
    }
  if (level == 25) quicksort(tab_temp,0,nearbyint((arr_size-1)*1/4),0);
  if (level == 50) quicksort(tab_temp,0,nearbyint((arr_size-1)*1/2),0);
  if (level == 75) quicksort(tab_temp,0,nearbyint((arr_size-1)*3/4),0);
  if (level == 95) quicksort(tab_temp,0,nearbyint((arr_size-1)*95/100),0);
  if (level == 99) quicksort(tab_temp,0,nearbyint((arr_size-1)*99/100),0);
  if (level == 997) quicksort(tab_temp,0,nearbyint((arr_size-1)*997/1000),0);

  if (level == 100) quicksort(tab_temp,0,arr_size-1,1);



    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    //Przypadek sortowania przez scalanie
    if(type == 1)
    {
    start = std::chrono::system_clock::now();
    merge_sort(tab_temp, 0, arr_size);
    end = std::chrono::system_clock::now();
    }

    if(type == 2)
    {
    start = std::chrono::system_clock::now();
    quicksort(tab_temp,0,arr_size-1,0);
    end = std::chrono::system_clock::now();
    }

    if(type == 3)
    {
    start = std::chrono::system_clock::now();
    introspective_Sort(tab_temp,arr_size);
    end = std::chrono::system_clock::now();
    }
    //if(isSorted(tab_temp,arr_size-1)==true) std::cout<<"Posortowano poprawnie"<<std::endl;
    //
    //else std::cout<<"Cos poszlo nie tak :("<<std::endl;
      elapsed_seconds = elapsed_seconds + end -start;
      //if(_isSorted(tab_temp,arr_size)==true) std::cout<<j<<". "<<elapsed_seconds.count()<<std::endl;
}
vector_TEMP.push_back(elapsed_seconds.count());
}
return vector_TEMP;
}


void TEST(void)
{
  int s = 1,type;
  while(s != 0)
  {
std::cout<<"Modul testujacy wydajnosc algorytmow sortowania"<<std::endl;
std::cout<<"-----------------------------------------------"<<std::endl;
std::cout<<std::endl;
std::cout<<"Jaki typ sortowania ma zostac pzetestowany: "<<std::endl;
std::cout<<"--------------------------------------------"<<std::endl;
std::cout<<"1 -- Sortowanie przez scalanie"<<std::endl;
std::cout<<"2 -- Sortowanie szybkie"<<std::endl;
std::cout<<"3 -- Sortowanie introspektywne"<<std::endl;
std::cout<<"0 -- Zakoncz"<<std::endl;
std::cout<<"Twoj wybor: "; std::cin >> s; std::cout<<std::endl;
if(s == 1 || s ==2 || s == 3)
{
std::cout << "Dane poczatkowe: " << std::endl;
std::cout << "1 -- Nieposortowanie" << std::endl;
std::cout << "2 -- Posortowane 25 %% poczatkowych wyrazow" <<std::endl;
std::cout << "3 -- Posortowane 50 %% poczatkowych wyrazow" <<std::endl;
std::cout << "4 -- Posortowane 75 %% poczatkowych wyrazow" <<std::endl;
std::cout << "5 -- Posortowane 95 %% poczatkowych wyrazow" <<std::endl;
std::cout << "6 -- Posortowane 99 %% poczatkowych wyrazow" <<std::endl;
std::cout << "7 -- Posortowane 99,7 %% poczatkowych wyrazow" <<std::endl;
std::cout << "8 -- Posortowane w odwrotnej kolejnosci" <<std::endl;
std::cout<<"Twoj wybor: "; std::cin >> type; std::cout<<std::endl;
}
//MODUL WYBORU SORTOWAN PRZEZ SCALANIE
int tab[] = {0,25,50,75,95,99,997,100};
std::vector<double>solution = main_modul(s,tab[type-1]);

Show_Solution(solution);
}
}
