#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int n, d; // n: 分子, d: 分母
} rational;

rational setr(int n, int d)
{
  rational z;
  if (d == 0) {
    fprintf(stderr, "Denominator must be nonzero.\n");
    exit(1);
  }
  z.n = n;
  z.d = d;
  return z;
}

void printr(rational z)
{
  printf("%d/%d\n", z.n, z.d);
}

rational mulr(rational x, rational y)
{
  int n = x.n * y.n;
  int d = x.d * y.d;
  rational z = setr(n, d);
  return z;
}

rational addr(rational x, rational y)
{
  int n = x.n * y.d + y.n * x.d;
  int d = x.d * y.d;
  rational z = setr(n, d);
  return z;
}

rational itor(int a)
{
  rational r;

  int n = a;
  int d = 1;
  r = setr(n,d);

  return r;
}

int rtoi(rational r)
{
  int a;

  a = r.n/r.d;

  return a;
}

void example3(void)
{
  rational x = setr(1, 3);
  int a = 3;
  rational y = itor(a); // 有理数に変換
  rational z = mulr(x, y); // z = 1/3 * 3
  int b = rtoi(z); // 整数に戻す
  printf("%d\n", b); // -> 1 整数として表示
}

void check2(int argc, char *argv[])
{
  rational x = setr(atoi(argv[1]), atoi(argv[2]));
  int a = atoi(argv[3]);
  rational y = itor(a);
  rational z = mulr(x, y); // z = x * y
  int b = rtoi(z); // 整数に戻す
  printf("%d\n", b); // -> 1 整数として表示
}

int main(int argc, char *argv[])
{
  // example3();
  check2(argc, argv);
  return 0;
}

