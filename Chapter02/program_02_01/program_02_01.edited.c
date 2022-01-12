#include "../../ThirdParty/CuTest.c"

/**
 * 顺序查找
 * @param a 数组（本例是要求其中的数据是已经升序排序的）
 * @param v 要从数据中查找的值
 * @param l 从哪个下标开始查询，一般为0
 * @param r 到哪个下标为止结束查询，一般为数组的大小 - 1
 * @return 如果找到了，则返回下标，如果没找到，则返回-1
 */
int search(int a[], int v, int l, int r) {
  int i;
  for (i = l; i <= r; i++) {
    if (v == a[i]) {
      return i;
    }
  }
  return -1;
}

/** 测试正确性 */
void test_correctness(CuTest *cuTest) {
  int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  for (int i = 0; i < 10; ++i) {
    int v = a[i];
    int res = search(a, v, 0, 9);
    printf("查找%d，得到的下标为：%d\n", v, res);
    CuAssertIntEquals(cuTest, i, res);
  }
  int res = search(a, 20, 0, 9);
  printf("查找20，得到的下标为：%d\n", res);
  CuAssertIntEquals(cuTest, -1, res);
}

main() {
  CuString *output = CuStringNew(); // 定义用于存储测试信息的字符串
  CuSuite *suite = CuSuiteNew();    // 新建测试套件
  SUITE_ADD_TEST(suite, test_correctness);  // 把 test_correctness 方法加入到测试套件中
  CuSuiteRun(suite);                // 运行测试套件
  CuSuiteDetails(suite, output);    // 把运行后的结果存入 output 中
  printf("%s\n", output->buffer);   // 打印测试结果
}
