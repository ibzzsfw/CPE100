#include <stdio.h>
#include <math.h>

int main()
{
//var declaration
 double U,X,Sx,Sy,deg,rad,tx,t,g=-9.81;
//input and error protecting
 char ch;
 printf("Welcome to the PROJECTILE MOTION calculator program....\n");
 do
 {
  printf("-----------------------------------------");
  printf("\nEnter initial velocity (m/s) : ");
  while(scanf("%lf%c",&U,&ch)==0 || ch!='\n')
  {
   rewind(stdin);
   printf("Invalid initial velocity input, please try again ");
  }
  printf("Enter start angle in degree : ");
  while(scanf("%lf%c",&deg,&ch)==0 || ch!='\n')
  {
   rewind(stdin);
   printf("Invalid angle input, please try again ");
  }
  printf("Enter distance from goal (m) : ");
  while(scanf("%lf%c",&X,&ch)==0 || ch!='\n')
  {
   rewind(stdin);
   printf("Invalid distance input, please try again ");
  }
//convert to rad
  rad=(M_PI/180)*deg;
//calculating
  tx=X/(U*cos(rad));
  Sy=(X*tan(rad)+((g*X*X/pow(U*cos(rad), 2))/2));
  t=-(2*U*sin(rad)/g);
  Sx=-(U*U*sin(2*rad)/g);
//analizing
  if (Sx<X)
  {
   printf("\nAt the goal line (%.2lf m. far from the net, time %.2lf sec.)\n",X-Sx,t);
   printf("——————————\nNO GOAL!!\n——————————\n");
   printf("The ball doesn’t even reach the net.\n");
  }
  else if (Sy>=2.44)
  {
   printf("\nAt the goal line (%.2lf m. from the ground., time %.2lf sec.)\n",Sy,tx);
   printf("——————————\nNO GOAL!!\n——————————\n");
   printf("The ball over the goal.\n");
  }
  else if (tx>0.5)
  {
   printf("\nAt the goal line (%.2lf m. from the ground, time %.2lf sec.)\n",Sy,tx);
   printf("——————————\nNO GOAL!!\n——————————\n");
   printf("The goalkeeper save the ball.\n");
  }
  else
  {
   printf("\nAt the goal line(%.2lf m. from the ground, time %.2lf sec.)\n",Sy,tx);
   printf("YES!! The ball goes into the goal,\n");
   printf("———————————————\nyou get a score.\n———————————————\n");
  }
     
  do
  {
   printf("Enter y to calculate again or n to exit.");
   scanf(" %c",&ch);
  }
  while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
 }
 while (ch == 'y'||ch=='Y');
    
return 0;
}
