#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /= 2) {
        
        for (i = gap; i < n; i++) {
            temp = arr[i];
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Vetor original:\n");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Vetor ordenado em ordem crescente:\n");
    printArray(arr, n);
    
    return 0;
}
