#include<stdio.h>

int main(){
	int n, i;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter the elements: ");
	for(i = 0; i< n; i++){
		scanf("%d ", &arr[i]);
	}
	insertionSort(arr, n);
	printf("\nAfter Sorting: ");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}

void insertionSort(int arr[], int n){
	int i, j;
	int temp;
	
	for(i=1; i<n; i++){
		temp = arr[i];
		j = i-1;
		
		while(j>=0 && temp < arr[j]){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = temp;
	}
}
