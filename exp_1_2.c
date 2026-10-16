//find largest element in the array
#include<stdio.h>
int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    printf("The largest element in the array is %d " , max);
    return 0;
}