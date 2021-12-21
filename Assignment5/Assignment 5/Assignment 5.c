#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//get int
int getint(int min,int max)
{
    int num;
    char ch;
    while (scanf("%d%c",&num,&ch)==0||ch!='\n'||num<min||num>max)
    {
        rewind(stdin);
        printf("Input error, Please input again... :");
    }
    return num;
}

//Fibonacci function
long int fib(int n)
{
  if(n<=1)
    return n;
  else
    return fib(n-1)+fib(n-2);
}

//Factorial function
long int fac(int n) //use in ncr
{
    int i;
    long int ans;
    for (ans=1,i=n;i>0;i--)
        ans=ans*i;
 return ans;
}

//nCr
long int ncr(int n,int r)
{
    long int ans;
    ans=fac(n)/(fac(r)*fac(n-r));
    return ans;
}

//GCD
long int gcd(int n,int r)
{
  if (n%r==0)
    return r ;
  else
    return gcd(r,n%r);
}

//LCM
long int lcm(int n,int r)
{
    long int ans;
    ans=(n*r)/gcd(n,r);
    return ans;
}

//get menu
int get_menu()
{
    int select;
    //system("cls");
    printf("***********************************************\n");
    printf("*            Please select program            *\n");
    printf("***********************************************\n");
    printf("*            1.Fibonacci function             *\n");
    printf("*            2.Combination number             *\n");
    printf("*            3.Find GCD(x,y)                  *\n");
    printf("*            4.Find LCM(x,y)                  *\n");
    printf("*            0.Exit program                   *\n");
    printf("***********************************************\n");
    printf("           (__)\n");
    printf("           (oo)\n");
    printf("    /-------|/\n");
    printf("   /|       ||\n");
    printf("~~~~~~~~~~~~~~ Hello._.\n");
    printf(" Enter menu number : ");
    select = getint(0,4);
    return select;
}

int main()
{
    int select,n,r;
    long int ans;
    do
    {
        select=get_menu();
        if (select==1)
        {
            printf("Calculate Fibonacci function\n");
            printf("Enter fibonacci term f(n)=f(0 to 45)\nn= : ");
            n=getint(0,45);
            ans=fib(n);
            printf("Answer of f(%d)=%ld\n",n,ans);
        }
        else if (select==2)
        {
            printf("Combination number (nCr)\n");
            printf("Enter n : ");
            n=getint(0,1000);
            printf("Enter r : ");
            r=getint(0,n);
            ans=ncr(n,r);
            printf("answer of %dC%d=%ld\n",n,r,ans);
        }
        else if (select==3)
        {
            printf("Find GCD (x,y)\n");
            printf("Enter x :");
            n=getint(1,1000);
            printf("Enter y :");
            r=getint(1, 1000);
            ans=gcd(n,r);
            printf("GCD(%d,%d)=%ld\n",n,r,ans);
        }
        else if (select==4)
        {
            printf("Find LCM (x,y)\n");
            printf("Enter x :");
            n=getint(1,1000);
            printf("Enter y :");
            r=getint(1, 1000);
            ans=lcm(n,r);
            printf("LCM(%d,%d)=%ld\n",n,r,ans);
        }
    } 
    while (select!=0);

return 0;
}


