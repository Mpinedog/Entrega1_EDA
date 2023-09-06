#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

void insertionsort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int element = arr[i];
    int j = i - 1;
    while (j > 0 and element < arr[j]) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = element;
  }
}

void merge(int arr[], int i, int j, int k) {
    int n1 = k - i + 1;
    int n2 = j - k;

    int L[n1], R[n2];

    for (int x = 0; x < n1; x++)
        L[x] = arr[i + x];
    for (int y = 0; y < n2; y++)
        R[y] = arr[k + 1 + y];

    int x = 0;
    int y = 0;
    int z = i;

    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) {
            arr[z] = L[x];
            x++;
        } else {
            arr[z] = R[y];
            y++;
        }
        z++;
    }

    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

void mergesort(int arr[], int i, int j) {
    if (i < j) {
        int k = i + (j - i) / 2;
        mergesort(arr, i, k);
        mergesort(arr, k + 1, j);
        merge(arr, i, j, k);
    }
  
}

//algoritmo split utilizado por quicksort para dividir una lista.
int split_qs(int arr[],int i,int j){
    int p = j; //last element is pivot postion
    //while start limit is less than end limit
    while (i < j) {
        //while elements on correct side -> next element
        while ((i < p) && (arr[i] <= arr[p])){
            i++;
        }
        while ((j > p) && (arr[j] >= arr[p])){
            j--;
        }
        //if elements not on correct side
        arr[i] = arr[j];
        //if we reach the pivot position
        if (i == p) {
            p = j;
        } else {
            if (j == p){
                p = i;
            }
        }
    }
    //returns pivots final position (post-order)
    return p;
}

void quickSort(int arr[],int i,int j){
    //repite splits con pivote de manera recursiva
    if (i < j) {
        int k = split_qs(arr, i, j);
        quickSort(arr, i, k - 1);
        quickSort(arr, k + 1, j);
    }
}

int main() {
  //filename es el nombre del archivo 
  string filename ="ruts_500000.txt";
  ifstream file(filename);

  if (!file.is_open()){
    cerr<<"error al abrir el archivo"<<endl;
    return 1;
  }
  //cambiar el largo del archivo que se va a leer
  const int maxlineas = 500000;
  int lineas[maxlineas];
  int countline = 0;

  string linea;
  while(getline(file, linea) && countline < maxlineas){
    int linea_int =stoi(linea);
    lineas[countline] = linea_int;

    countline++;
  }
  file.close();

  //insertionsort(lineas,maxlineas);

  clock_t time_req;
  time_req = clock();

  //insertionsort(lineas,maxlineas);
  //mergesort(lineas,1,maxlineas);
  quickSort(lineas,1,maxlineas);
  time_req =clock()-time_req;
  cout<< "tiempo: "<<(float)time_req/CLOCKS_PER_SEC << "segundos"<< endl;


  return 0;
}