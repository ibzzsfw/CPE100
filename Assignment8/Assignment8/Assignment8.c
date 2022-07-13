// Assignment8
// CPE100
// 63070501061
#include <math.h> //เรียกไลบรารี่ math
#include <stdio.h> //เรียกไลบรารี่ standard input/output
int get_int_interval(int min, int max) //ใช้รับจำนวนเต็มที่อยู่ในช่วง (min,max)
{
  int num; //ใช้เป็นจำนวนเต็มที่นำไปใช้
  char ch; //ใช้ตรวจสอบ charecter error
  while (scanf("%d%c", &num, &ch) == 0 || ch != '\n' || num < min ||
         num > max) //ในขณะที่ค่าที่ป้อนไม่ใช่จำนวนเต็มตัวเดียวที่อยู่ในช่วงที่กำหนด
  {
    rewind(stdin); //ล้างข้อมูลที่ป้อน
    printf("Input error, Please input again... : "); //แสดงผล Input error,
                                                     //Please input again... :
                                                     //แจ้งให้ผู้ใช้ทราบเพื่อป้อนใหม่
  } //จบการวนรอบเมื่อได้ตามกำหนด
  return num; // return เพื่อนำไปใช้
}
int get_double() //ใช้รับจำนวนจริงหนึ่งตัว
{
  double num; //ใช้เป็นจำนวนจริงที่นำไปใช้
  char ch; //ใช้ตรวจสอบ charecter error
  while (scanf("%lf%c", &num, &ch) == 0 ||
         ch != '\n') //ขณะที่ค่าที่ป้อนไม่ใช่จำนวนจริงตัวเดียว
  {
    rewind(stdin); //ล้างข้อมูลที่ป้อน
    printf("Input error, Please input again... : "); //แสดงผล Input error,
                                                     //Please input again... :
                                                     //แจ้งให้ผู้ใช้ทราบเพื่อป้อนใหม่
  } //จบการวนรอบเมื่อได้ตามกำหนด
  return num; // return เพื่อนำไปใช้
}
void print_Data(double data[], int *count) //ใช้แสดงผลชุดข้อมูล
{
  int i;                       //ใช้ i วนรอบ
  for (i = 0; i < *count; i++) //วนรอบค่า i ตั้งแต่ 0 ถึง *count-1
    printf("Data[%d] = %g\n", i,
           data[i]); //แสดงผล Data[i]=|Data[i]| และขึ้นบันทัดใหม่
}
int get_menu(double data[], int *count) //เลือกfunctionที่จะทดสอบ
{
  int select; //ใช้เป็นจำนวนเต็มที่นำไปใช้
  printf("************************\n"); //แสดงผล ************************
                                        //และขึ้นบันทัดใหม่
  printf("*Please select Function*\n"); //แสดงผล *Please select Function*
                                        //และขึ้นบันทัดใหม่
  printf("************************\n"); //แสดงผล ************************
                                        //และขึ้นบันทัดใหม่
  printf("*    1.Add data        *\n"); //แสดงผล *    1.Add data        *
                                        //และขึ้นบันทัดใหม่
  printf("*    2.Delete data     *\n"); //แสดงผล *    2.Delete data     *
                                        //และขึ้นบันทัดใหม่
  printf("*    3.Statistic       *\n"); //แสดงผล *    3.Statistic       *
                                        //และขึ้นบันทัดใหม่
  printf("*    0.Exit program    *\n"); //แสดงผล *    0.Exit program    *
                                        //และขึ้นบันทัดใหม่
  printf("************************\n"); //แสดงผล ************************
                                        //และขึ้นบันทัดใหม่
  if (*count != 0) //ถ้าตัวนับไม่เป็น0 (มีข้อมูล)
    print_Data(data, count); //แสดงผลชุดข้อมูล เพื่อให้ผู้ใช้เห็นข้อมูลทุกครั้งก่อนนำไปจัดการ
  else //มิฉะนั้น ให้แสดงผลว่าไม่มีข้อมูลล่าสุด
  {
    printf(
        "\n***************************\n"); //แสดงผล ***************************
                                            //และขึ้นบันทัดใหม่
    printf("*There is no current data.*"); //แสดงผล *There is no current data.*
                                           //และขึ้นบันทัดใหม่
    printf("\n***************************\n\n"); //แสดงผล
                                                 //***************************
                                                 //และขึ้นบันทัดใหม่
  }
  printf("Enter Function : "); //แสดงผล Enter Function :
  select = get_int_interval(0, 3); //ให้ผู้ใช้เลือกตั้งแต่ 0 ถึง 3
  return select; // return functionไปใช้ใน main
}
void add_Data(double data[], int *count) //ใช้เพิ่มข้อมูล
{
  int i;    //อินพุตที่นำไปวิเคราะห์
  double a; //ค่าตัวเลขในอินพุตที่นำไปเป็นข้อมูลหากผ่านการวิเคราะห์
  char ch;  //ใช้ทดสอบและจบการป้อน
  printf("\nInput data : "); //แสดงผล Input data :
  do                         //ทำ
  {
    i = scanf("%lf%c", &a, &ch); //ถ้าอินพุตมีจำนวนจริงหนึ่งจำนวนและอักขระหนึ่งตัว
    if (a <= 0)                  //ถ้า a<=0
      printf("\nSome input denied.\n"); //แสดงผล Some input denied. และขึ้นบันทัดใหม่
                                        //(ข้อมูลถูกปฏิเสธ)
    else if (i > 1 && a > 0) //มิฉะนั้นถ้า i>1 (ป้อนค่าผ่านเกณฑ์) และ a>0
    {
      data[*count] = a; //ให้ค่า a เป็นค่า data ลำัดับที่ *count
      *count = *count + 1; //เพิ่มค่า *count 1
    }
  } while (i != 0 && ch != '\n'); //วนรอบเมื่อ i!=0 และไม่ขึ้นบันทัดใหม่
  rewind(stdin); //ลบทิ้งส่วนที่ผิด
}
void delete_Data(double data[], int *count) //ใช้ลบข้อมูล
{
  int i, bin; // i ใช้วนรอบ,bin(binary) ใช้ตัดสินใจ
  double n; //ค่าที่ต้องการลบ
  printf("Input data that you want to delete : "); //แสดงผล Input data that you
                                                   //want to delete :
                                                   //เพื่อถามว่าอยากลบค่าใด
  n = get_double(); //รับจำนวนจริง n
  for (i = 0; i < *count; i++) //วนรอบค่า i ตั้งแต่ 0 ถึง *count-1
    if (data[i] == n) //ถ้า n มีค่าตรงกับข้อมูลตัวที่ i
    {
      print_Data(data, count); //โปรแกรมแสดงข้อมูลเพื่อให้ผู้ใช้ดูอีกครั้ง
      printf("There's %lf at Data[%d]\n", n,
             i); //โปรแกรมแจ้งว่ามีค่าข้อมูลนั้นๆที่ตำแหน่งใดเพื่อจะได้ลบให้ถูกตำแหน่ง
      printf(
          "Delete press 1, Don't press 0 : "); //โปรแกรมแจ้งให้ผู้ใช้ตัดสินใจว่าจะลบตำแหน่งนี้จริงหรือไม่
                                               //Delete press 1, Don't press 0
      bin = get_int_interval(0, 1); //รับค่าการตัดสินใจของผู้ใช้
      if (bin == 1) //ถ้าผู้ใช้ตัดสินใจลบ
      {
        for (int j = i; j < *count;
             j++) //วนรอบค่า j ตั้งแต่ i ถึง *count-1 (แก้ไขตำแหน่งตัวถัดๆไป)
          data[j] = data[j + 1]; //แก้ไขตำแหน่งตัวถัดๆไปให้ลดลงมา 1
        *count = *count - 1; //ลดจำนวนข้อมูลทั้งหมด 1 ในรอบที่ลบ
      }
    }
}
void statistic(double data[], int count, double *min, double *max, double *mean,
               double *sd) //ใช้คำนวณค่าทางสถิติ
{
  int i; //ใช้ i วนรอบ
  double sumMean = 0,
         sumSD = 0; // sumMean คือผลรวมที่จะนำไปหา*mean(ผลรวมกำลังหนึ่ง),sumSD
                    // คือผลรวมที่จะนำไปหา*sd(ผลรวมกำลังสอง)
  *min = *max = data[0]; //เริ่มต้นยังไม่ได้ค่า*min,*max
  for (i = 0; i < count; i++) //วนรอบค่า i ตั้งแต่ 0 ถึง *count-1
  {
    if (data[i] < *min) //ถ้า ข้อมูลตัวที่ i<*min
      *min = data[i]; //ข้อมูลตัวที่ i จะมาแทน *min เดิม
    if (data[i] > *max) //ถ้า ข้อมูลตัวที่ i>*max
      *max = data[i]; //ข้อมูลตัวที่ i จะมาแทน *max เดิม
    sumMean = sumMean + data[i]; //รวมกำลังหนึ่ง
    sumSD = sumSD + (data[i] * data[i]); //รวมกำลังสอง
  }
  *mean = sumMean / count;                   //คำนวนค่า *mean
  *sd = sqrt(sumSD / count - pow(*mean, 2)); //คำนวนค่า *sd
}
int main() {
  double data[50], min, max, mean, sd; //กำหนดตัวแปรไว้รองรับการชี้ข้อมูล
  int count = 0, select; //กำหนดตัวแปรไว้รองรับการชี้ข้อมูล,เลือกฟังก์ชัน
  do                     //ทำ
  {
    select = get_menu(data, &count); //รับค่า select จากผู้ใช้
    if (select == 1)                 //ถ้า select=1
    {
      add_Data(data, &count);   //เรียกใช้ add_Data
      print_Data(data, &count); //เรียกใช้ print_Data
    }
    if ((count == 0 && select == 2) ||
        (count == 0 && select == 3)) //ถ้าไม่มีข้อมูลแต่เลือกฟังก์ชัน 2,3
      printf(
          "\nThere is no data now, you can not use this function.\n\n"); //แสดงผล
                                                                         //There
                                                                         //is no
                                                                         //data
                                                                         //now,
                                                                         //you
                                                                         //can
                                                                         //not
                                                                         //use
                                                                         //this
                                                                         //function.
                                                                         //และขึ้นบันทัดใหม่
    else if (count != 0) //มิฉะนั้นถ้า count!=0
    {
      if (select == 2) //ถ้า select=2
      {
        delete_Data(data, &count); //เรียกใช้ delete_Data
        if (count == 0)            //ถ้า count=0
          printf("\nThere is no data now.\n\n"); //แสดงผล There is no data now.
                                                 //และขึ้นบันทัดใหม่
        else                        //มิฉะนั้น
          print_Data(data, &count); //เรียกใช้ print_Data
      } else if (select == 3)       //มิฉะนั้นถ้า select=3
      {
        if (count != 1) //ถ้า count!=1
        {
          statistic(data, count, &min, &max, &mean, &sd); //เรียกใช้ statistic
          printf("\nmin = %g\nmax = %g\nmean = %g\nsd = %g\n\n", min, max, mean,
                 sd); //แสดงผลค่าทางสถิติที่ได้จาก statistic
        } else        //มิฉะนั้น
          printf(
              "\nFunction available When there are at least 2 data.\n\n"); //แสดงผล
                                                                           //Function
                                                                           //available
                                                                           //When
                                                                           //there
                                                                           //are
                                                                           //at
                                                                           //least
                                                                           //2
                                                                           //data.
                                                                           //และขึ้นบันทัดใหม่
      }
    }
  } while (select != 0); //วนรอบหากยังไม่เลือก 0.Exit
  return 0;              // return 0 ก่อนจบการทำงาน
}
