#include <stdio.h>//เรียกไลบรารี่ standard input/output
#include <math.h>//เรียกไลบรารี่ math
int get_int_interval(int min,int max)//ใช้รับจำนวนเต็มที่อยู่ในช่วง (min,max)
{
    int num;//ใช้เป็นจำนวนเต็มที่นำไปใช้
    char ch;//ใช้ตรวจสอบ charecter error
    while  (scanf("%d%c",&num,&ch)==0||ch!='\n'||num<min||num>max)//ในขณะที่ค่าที่ป้อนไม่ใช่จำนวนเต็มตัวเดียวที่อยู่ในช่วงที่กำหนด
    {
        rewind(stdin);//ล้างข้อมูลที่ป้อน
        printf("Input error, Please input again... : ");//แสดงผล Input error, Please input again... :  แจ้งให้ผู้ใช้ทราบเพื่อป้อนใหม่
    }//จบการวนรอบเมื่อได้ตามกำหนด
    return num;//return เพื่อนำไปใช้
}
int get_int()//ใช้รับจำนวนเต็มหนึ่งตัว
{
    int num;//ใช้เป็นจำนวนเต็มที่นำไปใช้
    char ch;//ใช้ตรวจสอบ charecter error
    while (scanf("%d%c",&num, &ch)==0||ch!='\n')//ขณะที่ค่าที่ป้อนไม่ใช่จำนวนเต็มตัวเดียว
    {
        rewind(stdin);//ล้างข้อมูลที่ป้อน
        printf("Input error, Please input again... : ");//แสดงผล Input error, Please input again... :  แจ้งให้ผู้ใช้ทราบเพื่อป้อนใหม่
    }//จบการวนรอบเมื่อได้ตามกำหนด
    return num;//return เพื่อนำไปใช้
}
int get_menu()//เลือกเมนูที่จะทดสอบ
{
    int select;//ใช้เป็นจำนวนเต็มที่นำไปใช้
    printf("*****************************************\n");//แสดงผล ***************************************** และขึ้นบันทัดใหม่
    printf("*          Please select Test           *\n");//แสดงผล *          Please select Test           * และขึ้นบันทัดใหม่
    printf("*****************************************\n");//แสดงผล ***************************************** และขึ้นบันทัดใหม่
    printf("*            1.Test_Series1             *\n");//แสดงผล *            1.Test_Series1             * และขึ้นบันทัดใหม่
    printf("*            2.Test_Series2             *\n");//แสดงผล *            2.Test_Series2             * และขึ้นบันทัดใหม่
    printf("*            3.Test_Series3             *\n");//แสดงผล *            2.Test_Series3             * และขึ้นบันทัดใหม่
    printf("*            4.Test_Series4             *\n");//แสดงผล *            2.Test_Series4             * และขึ้นบันทัดใหม่
    printf("*            5.Test_Series5             *\n");//แสดงผล *            2.Test_Series5             * และขึ้นบันทัดใหม่
    printf("*            0.Exit program             *\n");//แสดงผล *            0.Exit program             * และขึ้นบันทัดใหม่
    printf("*****************************************\n");
    printf("Enter menu number : ");//แสดงผล Enter menu number :  และขึ้นบันทัดใหม่ โดยที่บันทัด 32 ถึง 42 แสดงผลให้ผู้ใช้พิจารณา
    select = get_int_interval(0,5);//ให้ผู้ใช้เลือกตั้งแต่ 0 ถึง 5
    return select;//return เมนูไปใช้ใน main
}
double even_sum(int n)//ใช้คำนวณอนุกรมเลขคู่ n ลำดับ
{
    int i,ans;//i ใช้วนรอบ, ans คือคำตอบนำไปใช้
    for (i=1,ans=0; i<=n; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง n โดย ans เริ่มต้นเป็น 0
        ans+=2*i;//แทนค่า ans ด้วย ans+2i
    return ans;//return ค่า ans ไปใช้ใน Test_Series1
}
double product(int n)//ใช้คำนวณผลคูณที่เป็นลำดับที่ n
{
    int i;//i ใช้วนรอบ
    double ans;//ans คือคำตอบนำไปใช้
    for (i=1,ans=1; i<=n; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง n และให้ ans เริ่มต้นเป็น 1(คูณแล้วค่าไม่หาย)
        ans*=i;//แทนค่า ans ด้วย ans*i
    return ans;//return ค่า ans ไปใช้ใน Test_Series1
}
void Test_Series1(int n,double fi[],double data[],int *count)//คำนวณผลรวมแต่ละพจน์จนถึง n ของอนุกรมเลขคู่หารด้วยผลคูณที่เป็นลำดับที่ n
{
    int i;//i ใช้วนรอบ
    double sum;//sum คือคำตอบที่นำไปใช้
    for(i=1,sum = 0; i<=n; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง n โดย sum เริ่มต้นเป็น 0
    {
        sum+=even_sum(i)/product(i);//แทนค่า sum ด้วย sum+อนุกรมเลขคู่หารด้วยแฟคทอเรียล i
        fi[i]=even_sum(i)/product(i);//นำค่าอนุกรมเลขคู่หารด้วยแฟคทอเรียล i ไปใช้ผ่านตัวแปร fi ที่ i ซึ่งเป็น Array
        data[i]=sum;//นำค่า sum ไปใช้ผ่านตัวแปร data ที่ i ซึ่งเป็น Array
        *count=i;//ให้ค่า i ตัวสุดท้ายเป็นค่า *count
    }
}
void Print_Series1(double fi[],double data[],int count)//แสดงค่าตัวแปรและผลรวม n เทอมแรกของอนุกรมเลขคู่หารด้วยผลคูณที่เป็นลำดับที่ n
{
    int i;//i ใช้วนรอบ, ans คือคำตอบนำไปใช้
    printf("Test#1\n");//แสดงผล Test#1
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    printf("*   i  *      fi    *     sum   *\n");//แสดงผล *   i  *      fi    *     sum   * และขึ้นบันทัดใหม่
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    for (i=1; i<=count; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง count
        printf("*  %2d  *%10.6lf  *%10.6lf *\n",i,fi[i],data[i]);//แสดงผลลำดับพจน์ที่ i,ค่าพจน์ที่ i และผลรวมถึงพจน์ที่ iและขึ้นบันทัดใหม่
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    printf("ans = %.6lf\n",data[count]);//แสดงผลค่าผลรวมสุดท้ายและขึ้นบันทัดใหม่
}
//Fibonacci fucntion
int fibo(int n)//ใช้คำนวณค่าฟิโบนักชีลำดับที่ n
{
    if(n<=1)//ถ้า n<=0
        return n;//return ค่า n
    else//มิฉะนั้น
        return fibo(n-1)+fibo(n-2);//return ค่า ฟิโบนักชีลำดับที่ n-1 ลบ ค่าฟิโบนักชีลำดับที่ n-2
}
void Test_Series2(int n,int fi[],int data[],int *count)//คำนวณfibonacci จํานวน n เทอมแรก เฉพาะคำตอบที่เป็นเลขคู่ > 0
{
    int i;//i ใช้วนรอบ
    for (i=1; *count<n; i++)//เริ่มวนรอบค่าขณะ i=1 และหยุดเมื่อค่า *count<n
    {
        if (fibo(i)%2==0)//ถ้าค่าฟิโบนักชีลำดับที่ i หารด้วยสองลงตัว(เป็นเลขคู่)
        {
            *count=*count+1;//เพิ่มค่า *count 1
            fi[*count]=i;//ให้ค่า i นั้น เป็นลำดับที่นำมาใช้
            data[*count]=fibo(i);//ให้ค่าฟิโบนักชีลำดับที่ i เป็นdata ตัวที่ *count
        }
    }
}
void Print_Series2(int fi[],int data[],int count)//ใช้แสดงผลลำดับการนับ,ลำดับที่นำมาใช้ และfibonacciค่านั้นซึ่งเป็นเลขคู่
{
    int i;//i ใช้วนรอบ
    printf("Test#2\n");//แสดงผล Test#2 และขึ้นบันทัดใหม่
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    printf("*  count *       i  *    fi     *\n");//แสดงผล *  count *       i  *    fi     * และขึ้นบันทัดใหม่
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    for (i=1; i<=count; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง count
        printf("*  %2d    *%8d  *%10d *\n",i,fi[i],data[i]);//แสดงผลลำดับการนับ,พจน์ที่นำมาใช้ และของพจน์นั้นและขึ้นบันทัดใหม่
    printf("*********************************\n");//แสดงผล ********************************* และขึ้นบันทัดใหม่
    printf("count = %d, ans = %d\n",count,data[count]);//แสดงผลลำดับการนับและค่าของพจน์สุดท้ายและขึ้นบันทัดใหม่
}
int is_prime(int n)//ใช้ตรวจสอบว่า n เป็นจำนวนเฉพาะหรือไม่
{
    int i;//i ใช้วนรอบ
    if (n<=1)//ถ้า n<=1
        return 0;//return 0 ไปใช้ใน Test_Series3 (ไม่เป็นจำนวนเฉพาะ)
    else//มิฉะนั้น
        for (i=2; i<n; i++)//วนรอบค่า i ตั้งแต่ 2 ถึง n-1
            if(n%i==0)//ถ้า n หารด้วย i ลงตัว
                return 0;//return 0 ไปใช้ใน Test_Series3 (ไม่เป็นจำนวนเฉพาะ)
    return 1;//return 1 ไปใช้ใน Test_Series3 (เป็นจำนวนเฉพาะ)
}
void Test_Series3(int min,int max,int fi[],int data[],int *count)//ใช้หาผลรวมของจำนวนเฉพาะที่อยู่"ระหว่าง"ค่า min, max
{
    int i,sum;//i ใช้วนรอบ, sum ใช้รวมค่า
    for (i=min+1,*count=0,sum=0; i<max; i++)//วนรอบค่า i ตั้งแต่ min+1 ถึง max-1 โดย *countและsum เริ่มจาก 0
    {
        if(is_prime(i)!=0)//ถ้า i เป็นจำนวนเฉพาะ
        {
            sum+=i;//แทนค่า sum ด้วย sum+i
            *count=*count+1;//เพิ่มค่า *count ขึ้น 1
            fi[*count]=i;//นำค่า i ในการวน(กรณีเป็นจำนวนเฉพาะ)ไปเป็นตัวนับ fi ตัวที่ *count
            data[*count]=sum;//นำค่า sum ไปเป็นตัวนับ data ตัวที่ *count
        }
    }
}
void Print_Series3(int fi[],int data[],int count)//แสดงผลลำดับการนับ,จำนวนพจน์และผลรวมของจำนวนเฉพาะที่อยู่"ระหว่าง"ค่า min, max
{
    int i;//i ใช้วนรอบ
    printf("Test#3\n");//แสดงผล Test#3 และขึ้นบันทัดใหม่
    printf("*************************\n");//แสดงผล ************************* และขึ้นบันทัดใหม่
    printf("*  no  *    i  *   sum  *\n");//แสดงผล *  no  *    i  *   sum  * และขึ้นบันทัดใหม่
    printf("*************************\n");//แสดงผล ************************* และขึ้นบันทัดใหม่
    for (i=1; i<=count; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง count
        printf("*  %2d  *%5d  *%5d   *\n",i,fi[i],data[i]);//แสดงผลลำดับการนับ,จำนวนพจน์และผลรวมของจำนวนเฉพาะที่อยู่"ระหว่าง"ค่า min, max และขึ้นบันทัดใหม่
    printf("*************************\n");//แสดงผล ************************* และขึ้นบันทัดใหม่
    printf("count = %d, sum = %d\n",count,data[count]);//แสดงผลจำนวนพจน์และผลรวมสุดท้าย และขึ้นบันทัดใหม่
}
void Test_Series4(int n,int fi[],int data[],int *count)//คำนวณผลรวมแต่ละพจน์จนถึง n ของอนุกรม (2i-1)(41-(2i-1))
{
    int i=1,sum=0;//i ใช้วนรอบ, sum ใช้รวมค่า
    for (i=1,sum=0; sum<=n; i++)//วนรอบค่า i เริ่มจาก i=1 จน sum=n โดย sum เริ่มจาก 0
    {
        sum+=(2*i-1)*(41-(2*i-1));//แทนค่า sum ด้วย sum+(2i-1)(41-(2i-1))
        fi[i]=(2*i-1)*(41-(2*i-1));//นำค่า (2i-1)(41-(2i-1)) ในการวนไปเป็นพจน์ fi ตัวที่ i
        data[i]=sum;//นำค่า sum ในการวนไปเป็น data ตัวที่ i
        *count=i-1;//นำค่า i ไปเป็นตัวนับลบตัวนับด้้วย 1เพราะเกินมาจากการ check แล้วนำมาคำนวณในครั้งสุดท้าย
    }
}
void Print_Series4(int fi[],int data[],int count)//แสดงผลลำดับพจน์, ค่าแต่ละพจน์และผลรวมแต่ละพจน์จนถึง n ของอนุกรม (2i-1)(41-(2i-1))
{
    int i;//i ใช้วนรอบ
    printf("Test#4\n");//แสดงผล Test#4 และขึ้นบันทัดใหม่
    printf("*****************************\n");//แสดงผล ***************************** และขึ้นบันทัดใหม่
    printf("*  i  *     fi   *    sum   *\n");//แสดงผล *  i  *     fi   *    sum   * และขึ้นบันทัดใหม่
    printf("*****************************\n");//แสดงผล ***************************** และขึ้นบันทัดใหม่
    for (i=1; i<=count; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง count
        printf("* %2d  *%8d  *%8d  *\n",i,fi[i],data[i]);//แสดงผลลำดับพจน์, ค่าแต่ละพจน์และผลรวมแต่ละพจน์จนถึง n ของอนุกรมและขึ้นบันทัดใหม่
    printf("*****************************\n");//แสดงผล ***************************** และขึ้นบันทัดใหม่
    printf("n = %d, ans = %d\n",count,data[count]);//แสดงผลค่าแต่และผลรวมพจน์สุดท้าย และขึ้นบันทัดใหม่
}
void Test_Series5(int n,int fi[],int data[],int *count)//คำนวณพจน์ที่ n ของลำดับเลขคณิตที่มีพจน์ทั่วไปเป็น a[n]=a[1]+(n-1)d ​ : a[i]=15i-14
{
    int i;//i ใช้วนรอบ
    for (i=1; i<=n; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง n
    {
        data[i]=(15*i)-14;//data ตัวที่ i (a[i]) เป็น 15i-14
        *count=i;//ให้ i เป็นตัวนับ *count
    }
}
void Print_Series5(int data[],int count)//แสดงลำดับพจน์และค่าของพจน์ที่ n ของลำดับเลขคณิตที่มีพจน์ทั่วไปเป็น a[n]=a[1]+(n-1)d ​ : a[i]=15i-14
{
    int i;//i ใช้วนรอบ
    printf("Test#5\n");//แสดงผล Test#5 และขึ้นบันทัดใหม่
    printf("*****************\n");//แสดงผล ***************** และขึ้นบันทัดใหม่
    printf("*  no *   term  *\n");//แสดงผล *  no *   term  * และขึ้นบันทัดใหม่
    printf("*****************\n");//แสดงผล ***************** และขึ้นบันทัดใหม่
    for (i=1; i<=count; i++)//วนรอบค่า i ตั้งแต่ 1 ถึง count
        printf("* %2d  *%8d *\n",i,data[i]);//แสดงผล ลำดับพจน์และค่าของพจน์ที่ n ของลำดับเลขคณิต และขึ้นบันทัดใหม่
    printf("*****************\n");//แสดงผล ***************** และขึ้นบันทัดใหม่
    printf("count = %d\n",count);//แสดงผล การนับที่เกิดขึ้น และขึ้นบันทัดใหม่
}
int main()
{
    int fi[20],data[20];//จอง Array ให้เก็บตัวแปรได้ 20 ตัว (เป็นจำนวนเต็ม)
    int n,count,select;//n ใช้เป็นค่าพารามิเตอร์ ,count ใช้นับและ select ใช้เป็นค่าเมนูที่ผู้ใช้เลือก
    do//ทำ
    {
        select = get_menu();//รับค่า select ด้วยฟังก์ชัน get_menu
        if (select==1)//ถ้า select=1
        {
            double fi[20],data[20];//จอง Array ให้เก็บตัวแปรได้ 20 ตัว (เป็นจำนวนจริง) ใช้เฉพาะ Series1 (Local)
            printf("Enter n : ");//แสดงผล Enter n :  เพื่อให้ผู้ใช้ป้อนค่า n
            n = get_int();//รับค่า n ด้วยฟังก์ชัน get_int
            Test_Series1(n,fi,data,&count);//เรียกใช้ฟังก์ชัน Test_Series1
            Print_Series1(fi,data,count);//เรียกใช้ฟังก์ชัน Print_Series1
        }
        else if (select==2)//ถ้า select=2
        {
            printf("Enter n : ");//แสดงผล Enter n :  เพื่อให้ผู้ใช้ป้อนค่า n
            n = get_int();//รับค่า n ด้วยฟังก์ชัน get_int
            Test_Series2(n,fi,data,&count);//เรียกใช้ฟังก์ชัน Test_Series2
            Print_Series2(fi,data,count);//เรียกใช้ฟังก์ชัน Print_Series2
        }
        else if (select==3)//ถ้า select=3
        {
            int min,max;//จองตัวแปร min,max
            printf("Enter max : ");//แสดงผล Enter max :  เพื่อให้ผู้ใช้ป้อนค่า max เพื่อกำหนดขอบบน
            max = get_int();//รับค่า max ด้วยฟังก์ชัน get_int
            printf("Enter min : ");//แสดงผล Enter min :  เพื่อให้ผู้ใช้ป้อนค่า min
            min = get_int_interval(0, max-1);//รับค่า min ด้วยฟังก์ชัน get_int_interval รับค่าได้ไม่เกิน max-1
            if (max-min==1)//ถ้าไม่มีจำนวนระหว่าง min และ max
                printf("There's no number in (min,max)\n");//แสดงผล There's no number in (min,max) และขึ้นบันทัดใหม่
            else//มิฉะนั้น
            {
                Test_Series3(min,max,fi,data,&count);//เรียกใช้ฟังก์ชัน Test_Series3
                Print_Series3(fi,data,count);//เรียกใช้ฟังก์ชัน Print_Series3
            }
        }
        else if (select==4)//ถ้า select=4
        {
            printf("Enter max of sum : ");//แสดงผล Enter max of sum :  เพื่อให้ผู้ใช้ป้อนค่า max
            n = get_int();//รับค่า n ด้วยฟังก์ชัน get_int
            Test_Series4(n,fi,data,&count);//เรียกใช้ฟังก์ชัน Test_Series4
            Print_Series4(fi,data,count);//เรียกใช้ฟังก์ชัน Print_Series4
        }
        else if (select==5)//ถ้า select=4
        {
            printf("Enter n : ");//แสดงผล Enter n :  เพื่อให้ผู้ใช้ป้อนค่า n
            n = get_int();//รับค่า n ด้วยฟังก์ชัน get_int
            Test_Series5(n,fi,data,&count);//เรียกใช้ฟังก์ชัน Test_Series5
            Print_Series5(data,count);//เรียกใช้ฟังก์ชัน Print_Series5
        }
        count=0;//reset ค่า count ใหม่
    }
    while (select!=0);//วนรอบต่อไปถ้า select ไม่เท่ากับ 0
    return 0;//return 0 ก่อนจบโปรแกรม
}
