#include "ThirdParty/CuTest.c" // ����CuTest����

/** ���� 1 + 1 �Ƿ����1 */
void test_add(CuTest *cuTest) {
  // ���� 1 + 1 == 1
  CuAssert(cuTest, "\r\ntest not pass", 1 + 1 == 1);
}

int main(void) {
  CuString *output = CuStringNew(); // �������ڴ洢������Ϣ���ַ���
  CuSuite *suite = CuSuiteNew();    // �½������׼�
  SUITE_ADD_TEST(suite, test_add);  // �� test_add �������뵽�����׼���
  CuSuiteRun(suite);                // ���в����׼�
  CuSuiteDetails(suite, output);    // �����к�Ľ������ output ��
  printf("%s\n", output->buffer);   // ��ӡ���Խ��
}
