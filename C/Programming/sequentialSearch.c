#include <stdio.h>

#define INDEX_SIZE 3

typedef struct{
	int index;
	int key;
} itable;
itable indexTable[INDEX_SIZE];

void sequentialSearch2(int a[], int begin, int end, int key){
	int i=begin;

	printf("\n %d 를 검색하여라 = ",key);
	while(i<end && a[i]<key) i++;

	if(a[i]==key)
		printf("%d 번째 검색성공! \n\n", (i-begin)+1);
	else
		printf("%d 번째 검색실패! \n\n", (i-begin)+1);
}

void makeIndexTable(int a[], int size){
	int i, n;
	n=size/INDEX_SIZE;
	if(size%INDEX_SIZE>0) n=n+1;
	for(i=0 ; i<INDEX_SIZE ; i++){
		indexTable[i].index=i*n;
		indexTable[i].key=a[i*n];
	}
}

void indexSearch(int a[], int n, int key){
	int i, begin, end;
	if(key<a[0]||key>a[n-1])
		printf("\n 찾는 키가 없습니다. 검색실패! \n");
	for((indexTable[i].key=key) && (indexTable[i+1].key>key)){
		begin=indexTable[i].index;
		end=indexTable[i+1].index;
		break;
	}
	if(i==INDEX_SIZE){
		begin=indexTable[i-1].index;
		end=n;
	}

	sequentialSearch2(a, begin, end, key);
}

void main(){
	int a[]={1,3,5,7,9,13,15};
	int n=7;
	printf("\n\t <<색인순차검색>> \n");
	makeIndexTable(a,n);
	indexSearch(a,n,9);
	indexSearch(a,n,6);

	getchar();
}