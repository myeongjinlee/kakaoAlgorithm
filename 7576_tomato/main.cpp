/*
2017-11-04 �����
https://www.acmicpc.net/problem/7576
DFS,BFS �˰���
���� �˰���

BFS�� ����
��¥�� ���°� ���� ( ���� Ǯ���°� ����)
pair�Լ� ������� �����ϵ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<utility> //pair ����� ���� header

using namespace std;

queue<pair<int, int>> q;
int result_day;
int st_num; //������ġ ����

void bfs(int st_num, vector<vector<int>> v,int m,int n) {	
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		
		if (curr.first + 1 < n && v[curr.first + 1][curr.second] == 0) {//�Ʒ�
			q.push(make_pair(curr.first + 1, curr.second));
			v[curr.first + 1][curr.second] = 1;
		}
		if (curr.first - 1 >= 0 && v[curr.first - 1][curr.second] == 0) {//��
			q.push(make_pair(curr.first - 1, curr.second));
			v[curr.first - 1][curr.second] = 1;
		}
		if (curr.second + 1 < m && v[curr.first][curr.second + 1] == 0) {//������
			q.push(make_pair(curr.first, curr.second + 1));
			v[curr.first][curr.second + 1] = 1;
		}
		if (curr.second - 1 >=0 && v[curr.first][curr.second - 1] == 0) {//����
			q.push(make_pair(curr.first, curr.second - 1));
			v[curr.first][curr.second - 1] = 1;
		}
		q.pop();
		st_num--;
		if (st_num == 0) { // �������� ��ä���� ��� ���߿� ���� ���Ѿ���.
			result_day++;
			st_num = q.size();
		}
	}
}

void solution(vector<vector<int>> v, int m, int n) {
	st_num = 0; //������ġ ����
	result_day = 0;
	//���� �� queue�� ��ġ ����
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
	//vector<vector<int>> v(m, vector<int>(n, 0)); // v[m][n] 0���� �ʱ�ȭ
	vector<vector<int>> v({
		vector<int>({0,0,0,0,0,0}),
		vector<int>({ 0,1,0,0,0,0 }),
		vector<int>({ 0,0,0,0,1,0 }),
		vector<int>({ 0,0,0,0,0,0 })
	});

	solution(v,m,n);
	
	printf("%d�� �ɸ���\n", result_day-1);
	return 0;
}

