#include <iostream>
#include "header.h"
#include <vector>

//Podzial tablicy na dwie - miejscem podzialu jest element z indeksem p
long int dividing(int tablica[],int p, long int r, int coeff)
  {
    long int x = tablica[p]; //Przypisanie do zmiennej x elementu rozdzielajacego
    long int i = p, j = r, w;
    while (true)
      {
        //MODUL DECYDUJACY O SORTOWANIU MALEJACYM BADZ ROSNACYM
        //coeff = 0 oznacza sortowanie rosnace
        if(coeff == 0)
        {
          while (tablica[j] > x) j--;
          while (tablica[i] < x) i++;
        }
         else
          {
            while (tablica[j] < x) j--;
            while (tablica[i] > x) i++;
          }
        //------------------------------------------------------
        //Zamiana miejscami dwoch elementow
        if (i < j)
          {
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
          }
          else return j; //Wyjscie z petli while i zwrocenie parametru j
        }
  }

//Glowna implementacja sortowania szybkiego quicksort
void quicksort(int tablica[],long int p,long int r,int coeff)
  {
    long int q;
    if (p < r)
      {
        q = dividing(tablica,p,r,coeff); //Wywolanie funkcji podzialu tablicy
        quicksort(tablica, p, q,coeff); //Rekurencyjne wywolanie funkji quicksort
        quicksort(tablica, q+1, r,coeff);//Rekurencyjne wywolanie funkcji quicksort
      }
    }
