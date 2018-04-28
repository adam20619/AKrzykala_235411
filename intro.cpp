//Funkcja - implementacja sortowania long introspektywnego
#include <bits/stdc++.h>
#include <cmath>
#include "header.h"

//Punkcja zamieniajaca miejscami dwie wartosci w tabeli
//Jako wejscie tablica wskaznikow oraz dwa indeksy i,j
void change_position(int *tab, long int i,long int j)
{
  long int temporary;   //definicja zmiennej pomocniczej
  temporary = tab[i];   //przypisanie elementy tabeli do zmiennej
  tab[i] = tab[j];      //Drugi element na miejsce pierwszego
  tab[j] = temporary;   //Element pomocniczy na drugie miejsce w tabeli
}

//Implementacja funkcji sortowania przez wstawianie
//Obsługa najgorszego przypadku QuickSorta
void InsertSort(int *tab, long int size)
{
	long int j;
  long int temporary;
  for (long int i = 1; i<size; ++i)
  {
    temporary = tab[i];
    for (j = i; j>0 && temporary < tab[j-1]; --j)
      tab[j] = tab[j-1];
    	tab[j] = temporary;
  }
}

//Część funkcji sortowania przez kopcowanie gdy M <= 0
void Heap(int *tab, long int i, long int size)
{
  long int coff;
  while (i <= size/2)
  {
    coff = 2*i;
    if (coff+1 <= size && tab[coff+1] > tab[coff]) coff += 1;
    if (tab[i] < tab[coff]) change_position(tab,i,coff);
      else break;
    i = coff;
  }
}

//Część główna sortowania przez kopcowanie dla M <= 0
void Heap_Sort(int *tab, long int size)
{
  for (long int i = size/2; i>0; --i) Heap(tab-1,i,size);
  for (long int i = size-1; i>0; --i)
  {
    change_position(tab,0,i); //Zamiana dwoch elementow
    Heap(tab-1,1,i);					//Rekurencyjne wywolanie funkcji Heap - składowej
  }
}

//Wyliczenie mediany trzech sąsiednich wartosci w tabeli
void Three_Values_Median(int *tab, long int &left, long int &right)
{
  if (tab[++left-1] > tab[--right]) change_position(tab,left-1,right);
  if (tab[left-1] > tab[right/2]) change_position(tab,left-1,right/2);
  if (tab[right/2] > tab[right]) change_position(tab,right/2,right);
  change_position(tab,right/2,right-1);
}

long int divide(int *tab, long int left, long int right)
{
	long int i, j;
  if (right >= 3) Three_Values_Median(tab,left,right);
  for (i = left, j = right-2; ; )
  {
    for ( ; tab[i] < tab[right-1]; ++i);
    for ( ; j >= left && tab[j] > tab[right-1]; --j);
    if (i < j) change_position(tab,i++,j--);
    else break;
  }
  change_position(tab,i,right-1);
  return i;
}

//Wlasciwa funkcja sortowania long introspektywnego
//Przyjete wartosci (tablica wskaznikow, size, depth coefficient)
void INTROSORT(int *tab, long int size, long int depth)
{
  long int i;
  if (depth <= 0)
  {
    Heap_Sort(tab,size);	//Wywolanie sortowania przez kopcowanie (heapsort)
    return;
  }
  i = divide(tab,0,size);
  if (i > 9) INTROSORT(tab,i,depth-1); //Rekurencyjne
  if (size-1-i > 9) INTROSORT(tab+i+1,size-1-i,depth-1);//Rekurencyjne
}

//FUnkcja wyliczająca glebokosc rekurencji
void introspective_Sort(int *tab, long size)
{
  //(long int)floor(2*log(size)/M_LN2) - rzutowanie na long int
  INTROSORT(tab,size,(long int)floor(2*log(size)/M_LN2));
  InsertSort(tab,size);
}
