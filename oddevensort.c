#include<stdio.h>

int main(){
	int n, i;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter the elements: ");
	for(i=0; i<n;i++){
		scanf("%d", &arr[i]);
	}
	oddEvenSort(arr, n);
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void oddEvenSort(int arr[], int n){
	int i, j;
	for(i=0; i<n;i++){
		if(i%2 == 0){
			for(j = 1; j<n; j+=2){
				if(arr[j] < arr[j-1])
					swap(&arr[j-1] , &arr[j]);
			}
		}
		else{
			for(j = 2; j<n; j+=2){
				if(arr[j]< arr[j-1])
					swap(&arr[j-1], &arr[j]);
			}
		}
	}
}
