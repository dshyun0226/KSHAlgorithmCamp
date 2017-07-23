#include <iostream>

using namespace std;

int N, M;
int queue[10010][3];
char maze[101][101];
bool visit[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(int argc, char* argv[]) {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		scanf("\n");
		for(int j=1; j<=M; j++){
			scanf("%c", &maze[i][j]);
		}
	}
	int head = 0, tail = 0;
	queue[head][0] = 1;
	queue[head][1] = 1;
	queue[head++][2] = 1;
	while(head>tail){
		int x = queue[tail][0], y = queue[tail][1], c = queue[tail++][2];
		for(int i=0; i<4; i++){
			int to_x = x + dx[i];
			int to_y = y + dy[i];
			if(to_x == 0 || to_x == N+1 || to_y == 0 || to_y == M+1) continue;
			if(maze[to_x][to_y]=='0' || visit[to_x][to_y]) continue;
			queue[head][0] = to_x;
			queue[head][1] = to_y;
			queue[head++][2] = c + 1;
			visit[to_x][to_y] = true;
			if(to_x == N && to_y == M){
				printf("%d\n", c+1);
				return 0;
			}
		}
	}
	return 0;
}
