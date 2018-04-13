#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int n, d; // n: 分子, d: 分母
} rational;

int gcd ( int a, int b )
{
  int c;
  if(a < b){
    c = a;
    a = b;
    b = c;
  }
  c = a%b;
  while(c != 0){
    a = b;
    b = c;
    c = a%b;
  }
  return b;
}

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

rational reductionr(int n, rational ary[])
{
  int temp;
  rational z = setr(0,1);
  for (int counter = 0; counter < n; counter++){
    z = addr(z, ary[counter]);
  }
  temp = gcd(z.d , z.n);
  z.n = z.n/temp;
  z.d = z.d/temp;
  return z;
}

void example6(void)
{
  rational ary[3];
  ary[0] = setr(1, 2);
  ary[1] = setr(2, 3);
  ary[2] = setr(3, 4);
  rational z = reductionr(3, ary);
  printr(z);
}

void check5(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  rational ary[n];
  for(int i = 0; i < n; i++) {
    ary[i] = setr(atoi(argv[2+i*2]), atoi(argv[3+i*2]));
  }
  rational z = reductionr(n, ary);
  printr(z);
}

int main(int argc, char *argv[])
{
  //example6();
  check5(argc, argv);
  return 0;
}
