#include<stdio.h>
int queue[1010];int edge[10010][2];bool visit[1010];
int bfs(){ int head=0, tail=0; queue[head++] = start; while(head>tail){  int x = queue[tail++];  for(int i=0;i<M;i++){   int s = edge[i][0], e = edge[i][1];   if(s==x && !visit[e]){    queue[head++] = e;   }   else if(e==x && !visit[s]){    queue[head++] = s;   }  } } return 0;}
int main(){ int N; scanf("%d %d %d", &N, &M, &start); for(int i=0;i<M;i++){  scanf("%d %d", &edge[i][0], &edge[i][1]); } bfs(start); return 0;}
