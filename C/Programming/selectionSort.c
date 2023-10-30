#include <stdio.h>

int size;

void SelectionSort(int a[], int size){
	int i, j, t, min, temp;
	printf("\n 정렬할 원소 : ");
	for(t=0 ; t<size ; t++)
		printf("%d", a[t])
	printf("\n\n <<<<<선택정렬수행>>>>> \n");
	for(i=0 ; i<size-1 ; i++){
		min=i;
		for(j=i+1 ; j<size ; j++){
			if(a[j]<a[min]) min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		printf("\n%d 단게 : ", i+1);
		for(t=0 ; t<size ; t++)
			printf("%3d", a[t]);
	}
}

void main()
{
	int list[8]={1,3,5,7,9,11,13,15};
	size=8;
	SelectionSort(list, size);

	getchar();
}