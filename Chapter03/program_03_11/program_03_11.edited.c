#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

/** 打印链表 */
void printf_link(char *msg, link l) {
  printf("%s\n", msg);
  link temp = l->next;
  while (temp != NULL) {
    printf("%d ", temp->item);
    temp = temp->next;
  }
  printf("\n");
}

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  int N = 5;
  link unsorted_link = malloc(sizeof(link)); // 未排序的链表
  link sorted_link = malloc(sizeof(link)); // 已排序的链表
  link handling_unsorted_node; // 当前正在处理的未排序的节点，用于外层循环
  link handling_sorted_node; // 当前正在处理的已排序的节点，用于里层循环
  link rest_link; // 剩余未处理的链表
  unsorted_link->next = NULL;
  sorted_link->next = NULL;
  int i;
  // for循环作用：初始化未排序的链表
  for (i = 0, handling_unsorted_node = unsorted_link; i < N; i++) {
    handling_unsorted_node->next = malloc(sizeof *handling_unsorted_node);
    handling_unsorted_node = handling_unsorted_node->next;
    handling_unsorted_node->next = NULL;
    handling_unsorted_node->item = rand() % 1000;
  }
  printf_link("未排序的链表：", unsorted_link);

  // for循环作用：遍历未排序的链表。
  for (handling_unsorted_node = unsorted_link->next;
       handling_unsorted_node != NULL;
       handling_unsorted_node = rest_link) {
    rest_link = handling_unsorted_node->next;
    printf("当前处理的节点：%d\n", handling_unsorted_node->item);
    // for循环作用：找出已排序的链表中，哪个节点的下一个节点的item比当前正在处理的待排序的结点的item大
    for (handling_sorted_node = sorted_link;
         handling_sorted_node->next != NULL;
         handling_sorted_node = handling_sorted_node->next) {
      if (handling_sorted_node->next->item > handling_unsorted_node->item) {
        break;
      }
    }
    // 以下两行，用于把待排序的节点插入到指定位置
    handling_unsorted_node->next = handling_sorted_node->next;
    handling_sorted_node->next = handling_unsorted_node;
  }
  printf_link("排序后的链表：", sorted_link);
}
