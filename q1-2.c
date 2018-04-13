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

rational divr(rational x, rational y)
{
  rational z;

  int n = x.n * y.d;
  int d = x.d * y.n;

  if (d == 0) {
    fprintf(stderr, "Division by zero.\n");
    exit(1);
  }

  z.n = n;
  z.d = d;

  return z;
}

rational subr(rational x, rational y)
{
  rational z;

  int n = x.n * y.d - y.n * x.d;
  int d = x.d * y.d;
  z = setr(n,d);

  return z;
}

void example2(void)
{
  rational x = setr(1, 2); // x = 1/2
  rational y = setr(2, 3); // y = 2/3

  rational a = mulr(x, y); // a = x * y
  printr(a); // -> 2/6

  rational b = addr(x, y); // a = x + y;
  printr(b); // -> 7/6
}

void check1(int argc, char *argv[])
{
  rational x = setr(atoi(argv[1]), atoi(argv[2]));
  rational y = setr(atoi(argv[3]), atoi(argv[4]));

  rational a = subr(x, y);
  printr(a);

  rational b = divr(x, y);
  printr(b);
}

int main(int argc, char *argv[])
{
  //example2();
  check1(argc, argv);
  return 0;
}

