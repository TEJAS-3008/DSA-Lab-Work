
void Bubblesort(int arr2[],int num){
      
    for (int i = 0; i< num; i++)
    {
        for (int j = 0; j < (num-1); j++)
        {
            if(arr2[j]>arr2[j+1]){
                int temp = arr2[j+1];
                arr2[j+1] = arr2[j];
                arr2[j] = temp;

            }
        }
        
    }

}

void Selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void Insertionsort(int arr[], int N) {

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
