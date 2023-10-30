#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8		// 정점의 수
#define INF	99				// 무한대(연결이 없는 경우) 

 
typedef struct adjmat{
	char city[8][256];							// 가중치들을 옮길 배열
	int weight[MAX_VERTICES][MAX_VERTICES];		// 각 정점간 가중치
	int distance[MAX_VERTICES];					// 시작 정점으로부터 최단 경로 거리
	int visited[MAX_VERTICES];					// 방문 정점 표시
} adjmat;

// 인접 행렬 초기화
adjmat nebi = {
	{NULL},
	{0, 60, 80, INF, 180, INF, INF, INF},
	{60, 0, 145, 110, INF, INF, INF, 280},
	{80, 85, 0, 44, 125, 190, 150, INF},
	{INF, 50, 44, 0, 169, 234, 185, 70},
	{180, INF, 125, 169, 0, 240, 185, 70},
	{270, 275, 190, 234, 240, 0, 40, 250},
	{194, 220, 114, 70, 239, 220, 180, 0},
	{0}, {0}
	};

// 최솟값을 선택하는 함수
int choose(int distance[], int n, int visited[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n ; i++)
		if (distance[i]< min && !visited[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

// 최단 거리 경로 구하는 함수
void shortest_path(int start, int n)
{
	int i, u, w;
	for (i = 0 ; i < n ; i++) 							// 초기화 
	{
		nebi.distance[i] = nebi.weight[start][i];
		nebi.visited[i] = FALSE;
	}
	nebi.visited[start] = TRUE;    						// 시작 정점 방문 표시
	nebi.distance[start] = 0;
	for (i = 0; i<n - 2; i++) {
		u = choose(nebi.distance, n, nebi.visited);		// 최솟값 선택 함수
		nebi.visited[u] = TRUE;
		for (w = 0 ; w < n ; w++)
			if (!nebi.visited[w])
				if (nebi.distance[u] + nebi.weight[u][w] < nebi.distance[w])
					nebi.distance[w] = nebi.distance[u] + nebi.weight[u][w];
	}
}
void main(int argc, char* argv[])
{
	int i, j, a;

	for(i = 0 ; i < MAX_VERTICES ; i++)
	{
	for(j = 0 ; j < MAX_VERTICES ; j++)
		nebi.city[i][j] = nebi.weight[i][j];
	}
	i=0;
	j=0;
	printf("|         |");
	for(j = 0 ; j < MAX_VERTICES ; j++)
	{
		i = 0;
		printf("| %7s |", argv[j+1]);
	}
	printf("\n---------------------------------------------------------------------------------------\n");
	for(i = 0 ; i < MAX_VERTICES ; i++)
	{
		j = 0;
		printf("| %7s |", argv[i+1]);
		for(j = 0 ; j < MAX_VERTICES ; j++)
			printf("| %7d |",nebi.city[i][j]);
		printf("\n---------------------------------------------------------------------------------------\n");
	}
	printf("\n");
	printf("현 위치에서 최적 경로 찾고 싶은 지역의 숫자 입력\n");
	printf("1 : 서울 - 2 : 인천 - 3 : 대전 - 4 : 전주 - 5 : 강릉 - 6 : 울진 - 7 : 부산 - 8 : 목포\n");
	scanf("%d", &a);			// 현재 위치 입력
	shortest_path(a - 1, MAX_VERTICES);
	printf("지정 된 지점에서 다른 지점으로의 각 최단 경로\n");
	for(i = 0 ; i < MAX_VERTICES ; i++)
	{
		printf("%s 으로부터 %s 까지 최단 거리 : %7d \n", argv[a], argv[i+1], nebi.distance[i]);
	}
}
