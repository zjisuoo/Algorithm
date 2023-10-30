#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_SIZE 25

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n; 									// 행과 열의 수
int group_id; 							// 단지의 번호로 첫번째 단지부터 1로 시작
int groups[MAX_SIZE * MAX_SIZE]; 		// 각 단지별 집의 수

int map[MAX_SIZE][MAX_SIZE]; 			// 지도
bool visited[MAX_SIZE][MAX_SIZE]; 		// 방문했는지를 표시하는 지도

// DFS - Stack
void dfs_stack(int x, int y) 
{
    stack< pair<int,int> > s; 			// 이용할 스택, (x,y) -> (행, 열)
    s.push(make_pair(x,y)); 			// pair를 만들어서 stack에 넣습니다.

    visited[x][y] = true;				// 처음 x,y를 방문 했기때문에
    groups[group_id]++;

    while(!s.empty()){

        x = s.top().first;				// 스택의 top 원소 꺼내기
        y = s.top().second;
        s.pop();

        for(int i = 0; i < 4; i++)		// 해당 위치의 주변을 확인
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n){				// 지도를 벗어나지 않고
                if(map[nx][ny] == 1 && visited[nx][ny] == false){	// 집이면서 방문하지 않았다면 -> 방문
                    visited[nx][ny]=true;
                    groups[group_id]++;								// 해당 단지의 집의 수를 증가시킴

                    s.push(make_pair(x,y)); 						// push하는 경우이기 때문에 현재 위치도 넣어준다.
                    s.push(make_pair(nx,ny)); 						// 스택에 현재 nx,ny도 푸시
                }
            }
        }   
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);
    }
    for(int i = 0; i < n; i++)								// 전체 지도 탐색
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j]==1 && visited[i][j]==false)		// 집이면서 방문하지 않았다면 -> 방문
            {
                group_id++;									// 해당 지역에 단지 id를 부여하고
                dfs_stack(i, j);							// 탐색
            }
        }
    }
    sort(groups + 1, groups + group_id + 1);				// 단지마다 집들의 수로 오름차순 정렬
    printf("%d\n", group_id);
    for (int i = 1; i <= group_id; i++) 
    {
        printf("%d\n", groups[i]);
    }
}
