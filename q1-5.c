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
  int c;
  rational z;
  if (d == 0) {
    fprintf(stderr, "Denominator must be nonzero.\n");
    exit(1);
  }
  c = gcd(n,d);
  //printf("c = %d\n",c);
  if(c < 0){
    c = 0 - c;
    //printf("じっこうしました");
  }
  //printf("改変後のc = %d\n",c);
  z.n = n/c;
  z.d = d/c;
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
  
  if(d < 0){
    n = 0 - n;
    d = 0 - d;
  }

  int c;

  if (d == 0) {
    fprintf(stderr, "Division by zero.\n");
    exit(1);
  }

  c = gcd(n, d);
  n = n/c;
  d = d/c;
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
  //printf("つうかしました\n");
  //printf("n = %d,d = %d\n,",n,d);
  return z;
}

void example5(void)
{
  rational x;
  x = setr(1016, 1638);
  printr(x);
}

void check4(int argc, char *argv[])
{
  rational x, y;
  {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    x = setr(a, b);
    y = setr(c, d);
  }
  {
    // addr
    rational z = addr(x, y);
    printr(z);
  }
  {
    // subr
    rational z = subr(x, y);
    printr(z);
  }
  {
    // mulr
    rational z = mulr(x, y);
    printr(z);
  }
  {
    // divr
    rational z = divr(x, y);
    printr(z);
  }
}

int main(int argc, char *argv[])
{
  //example5();
  check4(argc, argv);
  return 0;
}
