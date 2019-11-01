#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int map[64][64], m, n, start[2], end[2];

typedef struct {
    int queue[64][3], front, rear;
} Queue;
typedef struct {
    int stack[64][2], top;
} Stack;

Queue path;

void input() {
    int i, j;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
}

void bfs() {
    int k, next_i, next_j;
    int next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool book[64][64];
    memset(book, 0, sizeof(bool) * 64 * 64);
    path.queue[0][0] = start[0];
    path.queue[0][1] = start[1];
    path.queue[0][2] = -1;
    for (path.front = path.rear = 0;
         path.front <= path.rear && !(path.queue[path.rear][0] == end[0] &&
                                      path.queue[path.rear][1] == end[1]);
         path.front++) {
        for (k = 0; k < 4; k++) {
            next_i = path.queue[path.front][0] + next[k][0];
            next_j = path.queue[path.front][1] + next[k][1];
            if (next_i <= m && next_i > 0 && next_j > 0 && next_j <= n &&
                map[next_i][next_j] == 0 && !book[next_i][next_j]) {
                path.rear++;
                path.queue[path.rear][0] = next_i;
                path.queue[path.rear][1] = next_j;
                path.queue[path.rear][2] = path.front;
                book[next_i][next_j] = true;
            }
        }
    }
}

void output() {
    Stack result;
    int pre;
    result.top = -1;
    if (!(path.queue[path.rear][0] == end[0] &&
          path.queue[path.rear][1] == end[1]))
        puts("没有能走出迷宫的路线");
    for (pre = path.rear; path.queue[pre][2] != -1; pre = path.queue[pre][2]) {
        result.top++;
        result.stack[result.top][0] = path.queue[pre][0];
        result.stack[result.top][1] = path.queue[pre][1];
    }
    printf("(%d,%d)", start[0], start[1]);
    while (result.top >= 0) {
        printf("->(%d,%d)", result.stack[result.top][0],
               result.stack[result.top][1]);
        result.top--;
    }
}

int main() {
    scanf("%d%d", &m, &n);
    input();
    scanf("%d%d%d%d", start, start + 1, end, end + 1);
    bfs();
    output();
    return 0;
}
