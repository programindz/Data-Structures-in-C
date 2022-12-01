#include<stdio.h>

main(){
	int index;
	int arr[] = {1,2,3,4,5,6};
	index = binSearch(arr, 0, 5, 3);
	printf("Index of the element is %d", index);
}

int binSearch(int arr[], int low, int high, int val){
	int i;
	int mid;
	if(low<high){
		mid = low+high/2;
		if(arr[mid]== val)
			return mid;
		else if(arr[mid]<val){
			return binSearch(arr, mid+1, high, val);
		}
		else
			return binSearch(arr, low, mid-1, val);
	}
}
