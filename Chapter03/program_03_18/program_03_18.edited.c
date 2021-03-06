#include <stdio.h>

main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
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
  // for循环作用：把二维数组里的每一个元素赋值为0
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      adj[i][j] = 0;
    }
  }
  // for循环作用：把对角线(即横坐标与纵坐标相等)的值设置为1，表明每个节点跟自身是连通的
  for (i = 0; i < V; i++) {
    adj[i][i] = 1;
  }
  // while循环作用：把输入的两个数对应下标的二维数组中的两个点(沿对角线对称的两个点)的值赋值为1
  while (scanf("%d %d\n", &i, &j) == 2) {
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
