#include "ThirdParty/CuTest.c" // ����CuTest����

/**
 * ˳�����
 * @param a ���飨������Ҫ�����е��������Ѿ���������ģ�
 * @param v Ҫ�������в��ҵ�ֵ
 * @param l ���ĸ��±꿪ʼ��ѯ��һ��Ϊ0
 * @param r ���ĸ��±�Ϊֹ������ѯ��һ��Ϊ����Ĵ�С - 1
 * @return ����ҵ��ˣ��򷵻��±꣬���û�ҵ����򷵻�-1
 */
int search(int a[], int v, int l, int r) {
  int i;
  for (i = l; i <= r; i++)
    if (v == a[i]) return i;
  return -1;
}

void test_correctness(CuTest *cuTest) {
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int res = search(a, 5, 0, 9);
  CuAssertIntEquals(cuTest, 5, res);
}

int main(void) {
  CuString *output = CuStringNew(); // �������ڴ洢������Ϣ���ַ���
  CuSuite *suite = CuSuiteNew();    // �½������׼�
  SUITE_ADD_TEST(suite, test_correctness);  // �� test_add �������뵽�����׼���
  CuSuiteRun(suite);                // ���в����׼�
  CuSuiteDetails(suite, output);    // �����к�Ľ������ output ��
  printf("%s\n", output->buffer);   // ��ӡ���Խ��
}
