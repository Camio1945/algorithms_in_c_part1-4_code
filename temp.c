#include <stdio.h>

int main() {
  setbuf(stdout, NULL);
  printf("本程序需要在控制台输入若干行数字(0到7之间的整数)，每行两个数字(数字间用空格隔开)，用于表示两个点是连通的，如：\n"
         "0 1\n"
         "0 2\n"
         "0 5\n"
         "0 6\n"
         "0 7\n"
         "1 7\n"
         "2 7\n"
         "3 4\n"
         "3 5\n"
         "4 5\n"
         "4 6\n"
         "4 7\n"
  );
  printf("提示：控制台输入完成后，按回车，然后按快捷键：Ctrl + D （也可能是Ctrl + C 或 Ctrl + Z，不同平台不一样，多试试）\n");
  int i, j, V = 8, adj[V][V];
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      adj[i][j] = 0;
      if (i == j) {
        adj[i][j] = 1;
      }
    }
  }
  while (scanf("%d %d", &i, &j) == 2) {
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
  // for循环作用，打印出二维数组
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      printf("%3d", adj[i][j]);
    }
    printf("\n");
  }

}
