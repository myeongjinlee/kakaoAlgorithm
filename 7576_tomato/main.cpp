/*
2017-11-04 토요일
https://www.acmicpc.net/problem/7576
DFS,BFS 알고리즘
백준 알고리즘

BFS로 구현
날짜를 세는게 관건 ( 쉽게 풀리는걸 ㅅㅂ)
pair함수 기억하자 유용하드라
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<utility> //pair 사용을 위한 header

using namespace std;

queue<pair<int, int>> q;
int result_day;
int st_num; //시작위치 갯수

void bfs(int st_num, vector<vector<int>> v,int m,int n) {	
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		
		if (curr.first + 1 < n && v[curr.first + 1][curr.second] == 0) {//아래
			q.push(make_pair(curr.first + 1, curr.second));
			v[curr.first + 1][curr.second] = 1;
		}
		if (curr.first - 1 >= 0 && v[curr.first - 1][curr.second] == 0) {//위
			q.push(make_pair(curr.first - 1, curr.second));
			v[curr.first - 1][curr.second] = 1;
		}
		if (curr.second + 1 < m && v[curr.first][curr.second + 1] == 0) {//오른쪽
			q.push(make_pair(curr.first, curr.second + 1));
			v[curr.first][curr.second + 1] = 1;
		}
		if (curr.second - 1 >=0 && v[curr.first][curr.second - 1] == 0) {//왼쪽
			q.push(make_pair(curr.first, curr.second - 1));
			v[curr.first][curr.second - 1] = 1;
		}
		q.pop();
		st_num--;
		if (st_num == 0) { // 마지막에 다채워진 경우 나중에 제외 시켜야함.
			result_day++;
			st_num = q.size();
		}
	}
}

void solution(vector<vector<int>> v, int m, int n) {
	st_num = 0; //시작위치 갯수
	result_day = 0;
	//갯수 및 queue에 위치 삽입
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) {
				st_num++;
				q.push(make_pair(i, j));
			}
		}
	}
	bfs(st_num,v,m,n);
}

int main(void) {
	int m = 6, n = 4;
	//vector<vector<int>> v(m, vector<int>(n, 0)); // v[m][n] 0으로 초기화
	vector<vector<int>> v({
		vector<int>({0,0,0,0,0,0}),
		vector<int>({ 0,1,0,0,0,0 }),
		vector<int>({ 0,0,0,0,1,0 }),
		vector<int>({ 0,0,0,0,0,0 })
	});

	solution(v,m,n);
	
	printf("%d일 걸린다\n", result_day-1);
	return 0;
}

