#include<stdio.h>

void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int*, int*);

main(){
	int n, i;
	printf("Enter the size of Array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter the elements: ");
	for(i=0; i<n;i++){
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0 , n-1);
	printf("After Sorting:\n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}

void quickSort(int arr[], int low, int high){
	int pIndex;
	if(low<high){
		pIndex = partition(arr, low, high);
		quickSort(arr, low, pIndex -1);
		quickSort(arr, pIndex+1, high);
	}
}

int partition(int arr[], int low, int high){
	int pIndex = low;
	int i;
	
	for(i= low; i<high;i++){
		if(arr[i] < arr[high]){
			swap(&arr[i],  &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[high], &arr[pIndex]);
	return pIndex;

}


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}


