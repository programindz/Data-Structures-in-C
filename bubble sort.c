#include<stdio.h>
#define SWAP(a, b) {int tmp; tmp = a; a=b; b = tmp;}

main(){
    int arr[] = {2,5,8,6,9,7,90,3,1};
    //int i, j, temp;
    int low = 0, high = 8;

    /* //Selection Sort
    for(i = 0; i<7; i++){
        for(j=i+1; j<7;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    */
    //Bubble Sort
    /*
    for(i=0;i<6;i++){
        for(j=0;j<6-i;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }*/
    //Merge Sort
    quicksort(arr, low, high);

    for(int i = 0; i<8;i++){
        printf("%d ", arr[i]);
    }


}
void quicksort(int arr[], int low, int high){
    int pivot;
    if(low <= high){
        pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}
int partition(int arr[], int low, int high){
    int piv;
    piv = arr[(low+high)/2];
    while(low<high){
        while(arr[low]<piv)
            low++;
        while(arr[high]>piv)
            high--;
        if(low>=high)
            return high;
        SWAP(arr[low], arr[high]);
        low++;
        high--;
    }
}










