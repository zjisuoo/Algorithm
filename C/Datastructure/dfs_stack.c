#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType
{
	int top;
	int stack[MAX_VERTICES];
} GraphType;

void dfs_mat(GraphType *g, int v)
{
	while(!is_empty(S))
	{
		v = S.pop();
		if(v != )
	}
	// S.push(v)
	// while(not is_empty(S)) do
	// 	v = S.pop()
	//	if(v 방문 되지 않은 경우)
	// 		v 방문 되었다고 표시
	//		for all u 가 (v 에 인접한 정점) do
	//			if(u 가 아직 방문되지 않았으면)
	//				S.push(u)
}

int main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));

	init(g);

	for(int i = 0 ; i < 4 ; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	
	printf("깊이 우선 탐색");
	dfs_mat(g, 0);
	printf("\n");
	free(g);

	return 0;
}