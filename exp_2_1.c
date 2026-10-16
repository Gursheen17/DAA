//find exectution time of insertion sort algorithm
#include<stdio.h>
#include<time.h>

void InsertionSort(int arr[], int n){
    int j , key;
    for(int i = 1; i <n; i++ ){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = { 12, 23 ,5 , 65 ,34};
    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    InsertionSort(arr , n);
    end = clock();
    cpu_time_used = ((double) (end - start)/ CLOCKS_PER_SEC);
    printf("%f seconds\n" , cpu_time_used);
    printf("Sorted array : \n");
    for(int i = 0; i < n ; i++){
        printf("%d " , arr[i]);
    }
    return 0;
}