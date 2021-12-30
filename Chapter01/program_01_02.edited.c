#include <stdio.h>

/** ����N����ʾ����Ĵ�С */
#define N 10

int get_root(int id[], int p);

/**
 * ��ͨ���⣨�Ľ���1����
 * <pre>
 *   �������� program_01_01.edited.c ����ĸĽ��棬���ע�Ͳ����ظ���
 *   ����һ��ĳ����У�����ɷ�Ϊ�����ܣ�һ���ǲ��ң�һ���Ǻϲ������ҵ�Ч�ʺܸߣ����Ǻϲ���Ч�ʺܵͣ�ÿ�κϲ���Ҫ�������������еĽڵ㡣
 *   ����һ�汾�У����������ͽṹ��
 *      ������һ��һά����a����СΪ10��a[0]��a[9]�д��ֵ�ֱ�Ϊ0~9����ÿ��Ԫ�ص�ֵ����һ����ÿ���ڵ㶼�Ǹ��ڵ㡣
 *      ������Ϊ����a[i]��a[j]�ĸ��ڵ㲻һ��ʱ��i��j����ͨ�����ڵ�һ��ʱ��i��j��ͨ��
 *      ��a[1]��a[4]Ϊ���������ʼֵ���£�
 *          a[1] a[2] a[3] a[4]
 *          1    2    3    4
 *      ����`1 2`��a[1]��ֵ�ĳ���2��ע�������2ָ�����±�Ϊ2������a[1]�����ֵ�ҵ���Ӧ�±��е�ֵ��
 *                                ��ʱa[1]�����Ǹ��ڵ㣬����a[2]���ӽڵ㣬a[1]��a[2]ӵ����ͬ�ĸ��ڵ�a[2]������a[1]��a[2]����ͨ�ģ�
 *          a[1] a[2] a[3] a[4]
 *          2    2    3    4
 *      ����`3 4`��a[3]��ֵ�����4����ʱa[3]�����Ǹ��ڵ㣬����a[4]���ӽڵ㣬a[3]��a[4]ӵ����ͬ�ĸ��ڵ�a[4]������a[3]��a[4]����ͨ�ģ���
 *          a[1] a[2] a[3] a[4]
 *          2    2    4    4
 *      ����`1 4`������a[1]�Ѿ����Ǹ��ڵ��ˣ�����Ҫ�����ҵ�a[2]������a[2]�Ǹ��ڵ㣬���ǰ�a[2]�ҵ�a[4]���£���ʱ4���ڵ�ĸ��ڵ㶼��a[4]�������඼��ͨ�ˣ�
 *          a[1] a[2] a[3] a[4]
 *          2    4    4    4
 * </pre>
 *
 * @return
 */
main() {
  setbuf(stdout, NULL); // ����׼����Ļ��������㣬��ֹprintf����ʱ��ӡ
  int i, p, q, root_of_p, root_of_q, id[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
  }

  printf("������һ�����֣�10���ڣ������������м��Կո�ָ���\n");
  while (scanf("%d %d", &p, &q) == 2) {
    printf("����֮ǰ������Ϊ��\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    root_of_p = get_root(id, p);
    root_of_q = get_root(id, q);
    // ����ע�͵�����ԭ���д������һ�д��������� get_root �����Ĺ���
//    for(root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
//    for(root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      printf("\t��ͨ��%d %d\n", p, q);
      continue;
    }
    id[root_of_p] = id[root_of_q];
    printf("\t����ͨ��%d %d\n", p, q);
    printf("����֮�������Ϊ��\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    printf("\n");
  }
}

/**
 * ��ȡ���ڵ�
 * @param id ����
 * @param current_node ��ǰ�ڵ�
 * @return
 */
int get_root(int id[], int current_node) {
  // �����ǰ�����Ľڵ㲻�Ǹ��ڵ�
  while (id[current_node] != current_node) {
    // ����������������ڵ�
    current_node = id[current_node];
  }
  return current_node;
}
