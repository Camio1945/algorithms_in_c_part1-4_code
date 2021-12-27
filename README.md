# 《算法：C语言实现(第1-4部分)》的代码



## 一、版本与开发工具

原书版本：第3版。

开发工具：CLion。**执行C文件时，运行模式(Run)会有中文乱码问题，请使用调试模式(Debug)**

***

## 二、目录及文件说明

目录结构示意：

&emsp;&emsp;`Chapter01`：第1章

&emsp;&emsp;&emsp;&emsp;`program_01_01.edited.c`：第1章的第1个示例，其中的代码是经过修改的（至少会增加注释）
&emsp;&emsp;&emsp;&emsp;`program_01_01.original.c`：第1章的第1个示例，其中的代码是原书中的原始代码，一字未改（可能会不小心格式化了）

&emsp;&emsp;`Chapter01`：第2章

&emsp;&emsp;&emsp;&emsp;文件略

`temp.c`文件是一个临时文件，因为不想改动原书的代码，但时常又需要自己改改做测试，就会复制到`temp.c`中，可忽略。

***

## 三、`*.original.c`文件与`*.edited.c`文件对比

`program_01_01.original.c`是原书的代码：

```c
#include <stdio.h>

#define N 10000

main() {
  int i, p, q, t, id[N];
  for (i = 0; i < N; i++) id[i] = i;
  while (scanf("%d %d\n", &p, &q) == 2) {
    if (id[p] == id[q]) continue;
    for (t = id[p], i = 0; i < N; i++)
      if (id[i] == t) id[i] = id[q];
    printf(" %d %d\n", p, q);
  }
}
```

`program_01_01.edited.c`是我修改后的代码：

```c
#include <stdio.h>

/** 常量N，表示数组的大小 */
#define N 10

/**
 * 连通问题：
 * <pre>
 *  1. 连通问题场景举例：
 *      假如现在某城市要修改地铁站，有4个区分别是A、B、C、D，现在从A到B已经修好了（表明A和B是连通的），从C到D也已经修好了（即C和D也是连通的），那么请问现在张三从A站坐地铁能到达D吗？不能，因为A和D不能连通。
 *      那怎么让A和D连通呢？有多种方案，比如：
 *      1. 从A站直接修地铁到D站，张三坐车方案：A -> D
 *      2. 从B站修地铁到D站，张三坐车方案：A -> B -> D
 *      3. 从B站修地铁到C站，张三坐车方案：A -> B -> C -> D
 *  2. 本程序的目标：
 *      输入一组数字对，如：`1 2`、`3 4`，判断两个数之间是否连通，如果不连通，则让他们连通
 *  3. 本程序原理
 *      假设有一个一维数组a，大小为10，a[0]到a[9]中存的值分别为0~9，即每个元素的值都不一样。
 *      程序认为，当a[i]和a[j]的值不一样时，i和j不连通，当两个值一样时，i和j连通。
 *      以a[1]到a[4]为例，程序初始值如下：
 *          a[1] a[2] a[3] a[4]
 *          1    2    3    4
 *      输入`1 2`后，a[1]和a[2]的值改成一样，表明1和2连通了：
 *          a[1] a[2] a[3] a[4]
 *          2    2    3    4
 *      输入`3 4`后（到这里，1和2连通，3和4连通）：
 *          a[1] a[2] a[3] a[4]
 *          2    2    4    4
 *      输入`1 4`后（到这里1、2、3、4互相都连通了）：
 *          a[1] a[2] a[3] a[4]
 *          4    4    4    4
 * </pre>
 *
 * @return
 */
main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  int i, p, q, t, id[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
  }
  printf("请输入一对数字（10以内），两个数字中间以空格分隔：\n");
  while (scanf("%d %d", &p, &q) == 2) {
    printf("处理之前的数组为：\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    if (id[p] == id[q]) {
      printf("\t连通：%d %d\n", p, q);
      continue;
    }
    // 【关键代码段】
    for (t = id[p], i = 0; i < N; i++) {
      if (id[i] == t) {
        id[i] = id[q];
      }
    }
    printf("\t不连通：%d %d\n", p, q);
    printf("处理之后的数组为：\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    printf("\n");
  }
}
```

可以看到，增加了注释、打印一引导的语句、打印了方便查看的结果。

***

## 四、关于`*.test.c`文件

这些是测试文件，一般对于测试改进前的算法与改进后的算法的区别。

***

## 五、关于更新

原书中文版有470页，英文版有722页，我的学习进度非常非常慢，学一点更新一点。

学算法这种事你懂的，急不来的。

***

## 六、总体进度

### 第1章 

1. 程序1.1：[博客](https://blog.csdn.net/blueskybluesoul/article/details/122115288)、[视频](https://www.bilibili.com/video/BV1hD4y1c7xQ/)
2. 程序1.2：[博客](https://blog.csdn.net/blueskybluesoul/article/details/122164615)、[视频](https://www.bilibili.com/video/BV1Vu411D7SH)
2. 
