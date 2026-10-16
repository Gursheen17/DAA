//find sum of all numbers in an array and also the average 
#include<stdio.h>
int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=arr[i]; 
    }
    printf("The sum of all numbers in array is %d\n" , sum);
    int avg = sum/n;
    printf("The average of all numbers in array is %d", avg);
    return 0;
}