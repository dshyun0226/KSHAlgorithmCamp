#include <iostream>

using namespace std;

int N, M;
char maze[101][101];
bool visit[101][101];

int fmin = 20000;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y, int cnt){
	visit[x][y] = true;
	if(x == N && y == M){
		if(fmin > cnt) fmin = cnt;
		return 0;
	}
	for(int i=0; i<4; i++){
		int to_x = x + dx[i];
		int to_y = y + dy[i];
		if(to_x ==0 || to_x == N+1 || to_y == 0 || to_y == M + 1) continue;
		if(maze[to_x][to_y]=='0' || visit[to_x][to_y]) continue;
		dfs(to_x, to_y, cnt+1);
		visit[to_x][to_y] = false;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		scanf("\n");
		for(int j=1; j<=M; j++){
			scanf("%c", &maze[i][j]);
		}
	}
	dfs(1, 1, 1);
	printf("%d\n", fmin);
	return 0;
}
