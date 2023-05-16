#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define MAXN (100)
int N;
char map[MAXN + 10][MAXN + 10];
bool mark[MAXN + 10][MAXN + 10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool myfunction (pair<pair<int, int>, char> &i, pair<pair<int, int>, char> &j) {
	if (i.first.first > j.first.first) {
		return true;
	} else if (i.first.first == j.first.first) {
		return i.first.second > j.first.second;
	} else {
		return i.second > j.second;
	}
	return false;
}

void InputData() {
	cin >> N;
	for (int h = 0; h < N; h++) {
		cin >> map[h];
	}
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int bfs(int x, int y) {
	mark[x][y] = true;
	int ret = 1;
	queue<pair<int, int>> myQueue;
	myQueue.push({x, y});
	
	while (!myQueue.empty()) {
		auto current = myQueue.front(); myQueue.pop();
		for (int i = 0; i < 4; i++) {
			int newX = current.first + dx[i];
			int newY = current.second + dy[i];
			if (newX >= 0 && newX < N && newY >= 0 && newY < N && 
				!mark[newX][newY] && map[newX][newY] == map[x][y]) {
				myQueue.push({newX, newY});
				ret++; mark[newX][newY] = true;
			}
		}
	}
	
	return ret;
}	

int main() {
	fastIO();
	InputData();
	memset(mark, false, sizeof(mark));
	vector<pair<pair<int, int>, char>> data(3, {{0, 0},'a'});
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(mark[i][j] == false) {
				int count = bfs(i, j);
				if (map[i][j] == 'R') {
					data[0].first.first++; data[0].first.second += count;
					data[0].second = 'R';
				} else if (map[i][j] == 'G') {
					data[1].first.first++; data[1].first.second += count;
					data[1].second = 'G';
				} else {
					data[2].first.first++; data[2].first.second += count;
					data[2].second = 'B';
				}
			}
		}
	}
	
	sort(data.begin(), data.end(), myfunction);

	cout << data[0].second << " " << data[0].first.first << "\n";
	return 0;
}
