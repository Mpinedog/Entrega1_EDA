#include <iostream>
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

void split_qs(int arr[],int i,int j){
  int p =0;
}


int main() {
  int arr[9] = {1, 9, 8, 14, 12, 15, 2, 3, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, 0, n - 1);
  //insertionsort(arr, 9);

  cout << "Sorted array: ";
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
