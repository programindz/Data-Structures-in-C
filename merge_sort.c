#include<stdio.h>
#define max 10

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main(){
	int i;
	int arr[10]= {9,8,7,6,5,4,3,2,1,7};
	mergeSort(arr, 0, 9);
	
	for(i = 0; i< max; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}

void mergeSort(int arr[], int l, int h){
	int mid;
	if(l<h){
		mid = (l+h)/2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

void merge(int arr[], int l, int mid, int h){
	int c[50];
	int i,j,k;
	i = l;
	k = 0;
	j = mid + 1;
	
	while(i<= mid && j<=h){
		if(arr[i] < arr[j])
			c[k++] = arr[i++];
		
		else
			c[k++] = arr[j++];
		
	}
	while(i<=mid)
		c[k++] = arr[i++];
	while(j<= h)
		c[k++] = arr[j++];
		
	for(i=l,j=0;i<=h;i++,j++){
		arr[i] = c[j];
	}
}




