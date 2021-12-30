#include <stdio.h>

/** ����N����ʾ����Ĵ�С */
#define N 10

/**
 * ��ͨ���⣨�Ľ���1����
 * <pre>
 *   �������� program_01_02.edited.c ����ĸĽ��棬���ע�Ͳ����ظ���
 *   ����һ��ĳ����У�����ɷ�Ϊ�����ܣ�һ���ǲ��ң�һ���Ǻϲ������ҵ�Ч�ʺܸߣ����Ǻϲ���Ч�ʺܵͣ�ÿ�κϲ���Ҫ�������������еĽڵ㡣
 *   ����һ�汾�У����������ͽṹ��
 *      ������һ��һά����a����СΪ10��a[0]��a[9]�д��ֵ�ֱ�Ϊ0~9����ÿ��Ԫ�ص�ֵ����һ����ÿ���ڵ㶼�Ǹ��ڵ㡣
 *      ������Ϊ����a[i]��a[j]�ĸ��ڵ㲻һ��ʱ��i��j����ͨ�����ڵ�һ��ʱ��i��j��ͨ��
 *      ��a[1]��a[2]Ϊ���������ʼֵ���£�
 *          a[1] a[2] a[3]
 *          1    2    3
 *      ����`1 2`��a[2]��ֵ�ĳ���1��ע�������1ָ�����±�Ϊ1������a[1]�����ֵ�ҵ���Ӧ�±��е�ֵ��
 *                                ��ʱa[2]�����Ǹ��ڵ㣬����a[1]���ӽڵ㣬a[1]��a[2]ӵ����ͬ�ĸ��ڵ�a[1]������a[1]��a[2]����ͨ�ģ�
 *          a[1] a[2] a[3]
 *          1    1    3
 *      ����`2 3`��a[3]��ֵ�����1����ʱa[3]�����Ǹ��ڵ㣬����a[1]���ӽڵ㣬��ʱ3���ڵ㶼��ͨ�ˣ�a[2]��a[3]����a[1]���ӽڵ㣺
 *          a[1] a[2] a[3]
 *          1    1    1
 * </pre>
 *
 * @return
 */
main() {
  setbuf(stdout, NULL); // ����׼����Ļ��������㣬��ֹprintf����ʱ��ӡ
  int i, p, q, root_of_p, root_of_q, id[N], depth_arr[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
    depth_arr[i] = 1;
  }
  printf("������һ�����֣�10���ڣ������������м��Կո�ָ���\n");
  while (scanf("%d %d", &p, &q) == 2) {
    printf("����֮ǰ������Ϊ��\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    // ����ע�͵�����ԭ���д������һ�д��������� get_root �����Ĺ���
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      printf("\t��ͨ��%d %d\n", p, q);
      continue;
    }
    if (depth_arr[root_of_p] < depth_arr[root_of_q]) {
      id[root_of_p] = root_of_q;
      depth_arr[root_of_q] += depth_arr[root_of_p];
    } else {
      id[root_of_q] = root_of_p;
      depth_arr[root_of_p] += depth_arr[root_of_q];
    }
    printf("\t����ͨ��%d %d\n", p, q);
    printf("����֮�������Ϊ��\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    printf("\n");
  }
}

