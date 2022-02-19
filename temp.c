#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

/** 初始化链表 */
link init_link(int N) {
  link link_a = malloc(sizeof(link));
  link current_node = link_a;
  for (int i = 1; i <= N; ++i) {
    current_node->item = rand() % 1000;
    if (i == N) {
      current_node->next = NULL;
    } else {
      current_node->next = malloc(sizeof(link));
    }
    current_node = current_node->next;
  }
  return link_a;
}

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
  int N = 5;
  link unsorted_link = malloc(sizeof(link)); // 未排序的链表
  unsorted_link->item = -1;
  unsorted_link->next = NULL;
  link handling_unsorted_node = unsorted_link;
  for (int i = 0; i < N; ++i) {
    handling_unsorted_node->next = malloc(sizeof(link));
    handling_unsorted_node->next->item = rand() % 1000;
    handling_unsorted_node = handling_unsorted_node->next;
    handling_unsorted_node->next = NULL;
  }
  printf_link("未排序的链表：", unsorted_link);

  handling_unsorted_node = unsorted_link->next;
  link sorted_link = malloc(sizeof(link));
  sorted_link->item = -1;
  sorted_link->next = NULL;
  link handling_sorted_node;

  while (handling_unsorted_node != NULL) {
    link rest_link = handling_unsorted_node->next;
    handling_sorted_node = sorted_link;
    while (handling_sorted_node->next != NULL) {
      if (handling_sorted_node->next->item > handling_unsorted_node->item) {
        break;
      }
      handling_sorted_node = handling_sorted_node->next;
    }
    handling_unsorted_node->next = handling_sorted_node->next;
    handling_sorted_node->next = handling_unsorted_node;
    handling_unsorted_node = rest_link;
  }
  printf_link("排序后的链表：", sorted_link);


}
