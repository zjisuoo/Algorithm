#include <stdio.h>
#include <math.h>

typedef struct Point_tag
{
	int a, b;
}Point;

int get_distance(Point, Point);

int main()
{
	int re;
	Point p = {1, 2};
	Point q = {9, 8};

	re = get_distance(p, q);
	printf(" 두 점 사이의 거리 : %d\n", re);

	return 0;
}

int get_distance(Point p, Point q)
{
	double dis, distance, a_p, b_p;
	a_p = p.a - q.a;
	b_p = p.b - q.b;
	dis = a_p * a_p + b_p * b_p; 				// 두 점 사이 거리 루트 변환 전
	distance = sqrt(dis); 						// 루트 값

	return distance;
}