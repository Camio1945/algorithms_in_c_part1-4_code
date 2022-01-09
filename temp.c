#include "ThirdParty/CuTest.c" // 引入CuTest工具

/** 测试 1 + 1 是否等于1 */
void test_add(CuTest *cuTest) {
  // 断言 1 + 1 == 1
  CuAssert(cuTest, "\r\ntest not pass", 1 + 1 == 1);
}

int main(void) {
  CuString *output = CuStringNew(); // 定义用于存储测试信息的字符串
  CuSuite *suite = CuSuiteNew();    // 新建测试套件
  SUITE_ADD_TEST(suite, test_add);  // 把 test_add 方法加入到测试套件中
  CuSuiteRun(suite);                // 运行测试套件
  CuSuiteDetails(suite, output);    // 把运行后的结果存入 output 中
  printf("%s\n", output->buffer);   // 打印测试结果
}
