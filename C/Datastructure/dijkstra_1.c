#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 16				// 지역 최대 수(Location 수) 
#define TRUE 1				// TRUE는 1로 지정 
#define FALSE 0				// FALSE는 0으로 지정 
#define LOOP 10000			// 무한대(LOOP)는 10000으로 설정 
#define strMAX 10			// 지역 이름 최대 길이 

typedef struct fast{		// Dijkstra 테이블 생성용 구조체 
	int fast_long[MAX];		// 최단 거리 
	int fast_way[MAX];		// 최단경로중 도착 Location 바로 이전 위치 
}FAST;

char name[MAX][strMAX]={"서울","춘천","속초","시흥","수원",			//0~4번 도시 이름 
						"원주","강릉","천안","상주","보령",			//5~9번 도시 이름 
						"대전","전주","대구","광주","마산","부산"};	//10~16번 도시 이름 

void creat_dijkstra(FAST *, int);			// Dijkstra 테이블 생성 
void find_way(FAST *,int, int);				// 최단경로 역추적 

/********** 기본 입력 및 Dijkstra 테이블 구조체 선언 **********/ 
int main(){
	FAST fastSet;							// Dijkstra 테이블 선언 
	int start, end;							// 시작 위치, 도착 위치 (수치) 
	int i,check;							// 반복문 용 임시 변수 선언 
	char strStart[strMAX], strEnd[strMAX];	// 시작,도착 Location 변수 (문자열)
	 
	while(1){
		printf("[빠른길 찾기!] 종료를 원하시면 종료를 치세요\n"); 

		/***** 출발 도시 입력 *****/ 
		check=1;								// check(정상 입력 확인) 변수 초기화
		while(check){
			printf("[1] 출발도시명 : ");
			fflush(stdin); 						// stdin 버퍼 초기화 
			scanf("%s",&strStart);				// 출발도시 입력 대기 
			if(!strcmp(strStart,"종료")) exit(0); // 종료 입력시 프로그램 종료 
			
			/***** Exception 확인 *****/ 
			for(i=0;i<MAX;i++){
				if(!strcmp(name[i],strStart)){
					check=0;					// 정상입력일 경우 check 0로 변경 
					start=i;					// 출발 위치(수치) 입력 
					break;
				} 
			}
			if(check!=0){						// Location 이름 잘못 입력하였을 경우 
				printf("  [ERR] %s 은(는) 없는지역입니다.\n",strStart);
			}				
		}
		
		/***** 도착 도시 입력 *****/ 
		check=1;								// check(정상 입력 확인) 변수 초기화 
		while(check){
			printf("[2] 도착도시명 : ");
			fflush(stdin);						// stdin 버퍼 초기화 
			scanf("%s",&strEnd);				// 도착도시 입력 대기 
			if(!strcmp(strEnd,"종료")) exit(0);	// 종료 입력시 프로그램 종료 
			/***** Exception 확인 *****/ 
			for(i=0;i<MAX;i++){
				if(!strcmp(name[i],strEnd)){
					check=0;					// 정상입력일 경우 check 0로 변경 
					end=i;						// 도착 위치(수치) 입력 
					break;
				} 
			}
			if(check!=0){						// Location 이름 잘못 입력하였을 경우 
				printf("  [ERR] %s 은(는) 없는지역입니다.\n",strEnd);
			}				
		}
		
		/***** Exception 확인 *****/ 
		if(start!=end){							// 출발,도착 지역이 다른 경우 
			creat_dijkstra(&fastSet,start);		// Dijkstra 테이블 생성 
			printf("  [PRT] ");
			find_way(&fastSet,start,end);  		// 최단경로 출력 
			// 도착지역에 대한 최단거리 출력 
			printf(", 최단거리 = %dkm\n\n",fastSet.fast_long[end]);
		}
		else{									// 출발, 도착 지역이 같은 경우 
			printf("  [ERR] 같은 장소는 갈수 없습니다.\n");
		}
	}
	return 0;
}

/********** Dijkstra 테이블 생성 **********/ 
void creat_dijkstra(FAST *fastSet, int start){
	/***** 기본 지역 정보 *****/ 
	int location[MAX][MAX]={
		0,70,LOOP,30,40,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		70,0,90,LOOP,LOOP,65,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,90,0,LOOP,LOOP,LOOP,35,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		30,LOOP,LOOP,0,25,LOOP,LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		40,LOOP,LOOP,25,0,75,LOOP,65,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,65,LOOP,LOOP,75,0,85,LOOP,80,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,LOOP,35,LOOP,LOOP,85,0,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,280,
		LOOP,LOOP,LOOP,LOOP,65,LOOP,LOOP,0,LOOP,100,80,LOOP,LOOP,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,80,LOOP,LOOP,0,LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,95,LOOP,LOOP,LOOP,100,LOOP,0,LOOP,LOOP,LOOP,110,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,80,LOOP,LOOP,0,50,105,LOOP,LOOP,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,50,0,LOOP,30,85,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,95,LOOP,105,LOOP,0,LOOP,55,75,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,110,LOOP,30,LOOP,0,40,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,85,55,40,0,LOOP,
		LOOP,LOOP,LOOP,LOOP,LOOP,LOOP,280,LOOP,LOOP,LOOP,LOOP,LOOP,75,LOOP,LOOP,0							
	};
	
	int visited[MAX],next,temp;
	int i, j, k;
	
	/***** 변수 초기화 *****/ 
	for(i=0;i<MAX;i++){
		visited[i]=0;				// 방문한 지역 변수 
		fastSet->fast_way[i]=start;	// 최단경로중 도착 Location 바로 이전 위치 
	}
	next=start;						// 시작 지역 입력후 테이블 생성 (처음 시작 위치) 
	
	/***** Dijstra 테이블 생성 *****/
	for(i=0;i<MAX;i++){				
		for(j=0;j<MAX;j++){
			/***** 첫 최단경로 테이블 값을 시작위치에서의 값으로 입력 *****/ 
			if(i==0){
				fastSet->fast_long[j]=location[start][j];	// 시작위치에서의 값 입력 
				visited[start]=TRUE;						// 시작위치 방문 처리 
			}
			else{
				// 새로 찾은 거리가 현재 거리보다 가까운 경우 값 변경 
				if((fastSet->fast_long[j])>(fastSet->fast_long[next]+location[next][j])){
					// 새로 찾은 거리 입력 
					fastSet->fast_long[j]=fastSet->fast_long[next]+location[next][j];
					// 새로 찾은 지역(가까운 노드 바로 이전 지역 위치 입력)
					fastSet->fast_way[j]=next;
				}
			}
		}
		temp=LOOP;		// 비교용 변수 LOOP로 초기화 

		for(k=0;k<MAX;k++){
			/***** 방문하지 않은 지역중 가장 temp(다른 지역 값)보다 작은 경우 *****/ 
			if((temp>fastSet->fast_long[k])&&(visited[k]==FALSE)){
				temp=fastSet->fast_long[k];		// 작은 거리 값 입력 
				next=k;							// 다음 이동할 지역 입력 
			}
		}
		visited[next]=TRUE;						// 다음 이동할 지역 방문으로 처리 
	}
}

/********** 최단경로 역추적 **********/ 
void find_way(FAST *fastSet,int start,int find){
	int i, set, way[MAX];
	
	/***** 최단경로 변수 초기화 *****/ 
	way[0]=start;			// 시작 지역(수치)를 맨처음 배열에 삽입 
	for(i=1;i<MAX;i++){
		way[i]=-1;			// 모든 나머지 배열 값을 -1로 초기화 
	}
	set=MAX-1;				// 배열 최대개수 셋팅
	/***** 역순으로 된 경로를 정순으로 정렬 *****/ 
	while(find!=start){
		way[set]=find;		// 배열 뒷부분부터 경로 입력 (정순으로 정렬 과정) 
		set--;				// set -1 (뒤에서 앞으로 1칸 이동) 
		find=fastSet->fast_way[find];	// find에 이전위치에 대한 가까운 경로 값 입력
	}
	
	/***** 정순으로 된 경로를 출력 *****/ 
	for(i=0;i<MAX;i++){
		if(way[i]!=-1){						// 배열값이 -1이 아닌경우만 출력 
			printf("%s",name[way[i]]);		// 위치값에 대한 지역 이름(문자열) 출력 
			if(i!=(MAX-1)){					// 마지막 경로가 아닌경우 -> 출력 
				printf(" -> ");
			} 
		}
	}		
}