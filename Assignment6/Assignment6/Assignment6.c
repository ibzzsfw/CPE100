#include <math.h>
#include <stdio.h>
// code referred from chapter3 page23
double getDouble() {
  double num;
  char ch;
  while (scanf("%lf%c", &num, &ch) == 0 || ch != '\n') {
    rewind(stdin);
    printf("Input error, Please input again... :");
  }
  return num;
}

double diff(double a, double b, double c, double Xp) {
  double ans, f, df;
  f = (a * Xp * Xp) + (b * Xp) + c;
  df = (2 * a * Xp) + b + 0;
  if (df == 0)
    Xp += 0.00001;

  ans = f / df;
  return ans;
}

int Newton_Raphson(double a, double b, double c, double err, double Xp,
                   double *Xn) {
  double delta, count = 0;
  do {
    delta = diff(a, b, c, Xp);
    *Xn = Xp - diff(a, b, c, Xp);
    Xp = *Xn;
    count++;
  } while (fabs(delta) > err && count <= 1000);

  if (count > 1000)
    return 0;
  else
    return count;
}

void Calculate_Newton_Ralphson() {
  double X1, X2, a, b, c, err = 0.00001, Xp1 = -100.123, Xp2 = 100.123;
  int count;
  /*printf("Enter Xp1 :");
  Xp1=getDouble();
  printf("Enter Xp2 :");
  Xp2=getDouble();
  printf("Enter error :");
  err=getDouble();*/
  // For any values by user
  printf("\nEnter a : ");
  a = getDouble();
  printf("Enter b : ");
  b = getDouble();
  printf("Enter c : ");
  c = getDouble();
  count = Newton_Raphson(a, b, c, err, Xp1, &X1);
  count = Newton_Raphson(a, b, c, err, Xp2, &X2);
  if (count == 0 || (a == 0 && b == 0))
    printf("\nthis equation does not have any real answers. \n");
  else if (fabs(X1 - X2) <= 0.0001)
    printf("x=%lf\n", (X1 + X2) / 2); // For more precisely answer
  else
    printf("x1=%lf\nx2=%lf\n", X1, X2);
}

int main() {
  char ch;
  printf("\nNewton-Raphson method\nfor ax^2+bx+c=0\n");
  do {
    Calculate_Newton_Ralphson();
    do {
      printf("\nEnter y to use again or n to exit. : ");
      scanf(" %c", &ch);
    } while (ch != 'y' && ch != 'Y' && ch != 'n');
  } while (ch == 'y' || ch == 'Y');
  return 0;
}
