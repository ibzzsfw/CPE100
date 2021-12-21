#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *strlwr(char *buff)
/*
เปลี่ยนสตริงเป็นพิมพ์เล็กโดยเปลี่ยนทีละตัว macOS มีปัญหาในการใช้ strlwr โดยตรง หากใช้ใน windows ไม่จำเป็นต้องมีส่วนตรงนี้
 */
{
    unsigned char *p = (unsigned char *)buff;
    while (*p)
    {
        *p = tolower((unsigned char)*p);
        p++;
    }
    return buff;
}
void add_space(char *buff)//เพิ่มช่องว่างระหว่าง Token
{
    char str[255] = "" ;//เริ่มต้นให้เป็นสตริงว่าง
    int i,j;
    unsigned long max;
    for(i=0,j=0,max=strlen(buff);i<=max;i++)//วนรอบตั้งแต่ 0 ถึงความยาวของสตริง
        if (strchr("+-*/^(),",buff[i]) != NULL)//ถ้าพบ + - * / ( ) , ใน buff ที่ i
        {
            str[j++]=' ';//เพิ่มช่องว่างใน str (จะอยู่หน้าสุด) จากนั้นเพิ่มค่า j ขึ้น 1
            str[j++]=buff[i];//นำ buff มาต่อ จากนั้นเพิ่มค่า j ขึ้น 1
            str[j++]=' ';//เพิ่มช่องว่างใน str (จะอยู่หลังสุด) จากนั้นเพิ่มค่า j ขึ้น 1
        }
        else//มิฉะนั้น
            str[j++]=buff[i];//buff ที่ i จะเป็น str ที่ j เลย จากนั้นเพิ่มค่า j ขึ้น 1
    strcpy(buff,str);//คัดลอก str ไปใส่ใน buff หลัก
}
int split(char *buff, char token[][20])//แบ่ง string ใหญ่ๆออกเป็น Token จำนวน count Tokens
{
    int count=0;//ตัวนับจำนวน Tokens
    char *tok;//
    tok = strtok(buff," ");//
    while(tok!=NULL)
    {
        strcpy(token[count++],tok);
        tok = strtok(NULL," ");
    }
    return count;
}
int check_number(char *str, double *n)//ตรวจสอบว่าtoken นั้นเป็นตัวเลขหรือไม่
{
    char ch;//
    if (sscanf(str,"%lf%c",n,&ch)==1)//ถ้าสิ่งที่อ่านได้จากสตริงเป็นจำนวนจริง
        return 1;//รีเทิร์น 1
    else//มิฉะนั้น
        return 0;//รีเทิร์น 0
}
int check_operator(char *str)//ตรวจสอบว่าtoken นั้นเป็นตัวดำเนินการหรือไม่
{
    if ((strlen(str)==1)&&(strchr("+-*/^()", str[0])!=NULL))//ถ้ามีสตริงที่ยาว 1 อักษรและสตริงนั้นเป็นหนึ่งใน + - * / ^ ( )
        return 1;//รีเทิร์น 1
    else//มิฉะนั้น
        return 0;//รีเทิร์น 0
}
int check_function(char *str)//ตรวจสอบว่าtoken นั้นเป็นรูปแบบของฟังก์ชันหรือไม่
{
    char function_name[15][10] = {"sin","cos","tan","asin","acos","atan","sqrt","pow","log","exp","abs"};//รายการฟังก์ชันที่ตรวจสอบได้
    int function_count=11,i=0;//ตัวนับทั้งหมดเท่ากับรายการ
    char buff[20];//ใช้เป็นตัวกลางในการพิจารณา
    strcpy(buff,str);//คัดลอกอินพุตไปใน buff เพื่อนำไปพิจารณา
    strlwr(buff);//เปลี่ยนทุกตัวอักษรเป็นพิมพ์เล็ก
    while (i<function_count&&strcmp(function_name[i], buff)!=0)//ขณะที่ตัวนับเริ่มต้นยังน้อยกว่าตัวนับทั้งหมด และ buff ยังไม่เหมือนกับรายการฟังก์ชันนั้นๆ
        i++;//เพิ่มตัวนับไปเรื่อยๆ
    if(i<function_count)//ถ้าตัวนับยังน้อยกว่าจำนวนรายการขณะที่พบ
        return 1;//รีเทิร์น 1
    else//มิฉะนั้น
        return 0;//รีเทิร์น 0
}
int check_identifier(char *str)//ตรวจสอบว่าtoken นั้นเป็นรูปแบบของตัวบ่งชี้หรือไม่
{
    int i,j=1;
    if ((isalpha(str[0]))||str[0]=='_')//ถ้าตัวแรกเป็นตัวอักษรหรือ _ (ขีดล่าง)
    {
        for (i=1; i<strlen(str); i++)//วนรอบตั้งแต่ 1ถึง ความยาวสตริง-1
            if(!(isalpha(str[i])||isdigit(str[i])||str[i]=='_'))//ถ้าไม่เป็นอักขระ หรือ เป็นตัวเลข หรือ เป็นขีดล่าง
                j=0;
        return j;//รีเทิร์นค่า j
    }
    else//มิฉะนั้น
        return 0;//รีเทิร์น 0
}
int check_terminate (char *str)//ตรวจสอบว่าtoken นั้นเป็นรูปแบบของคำจบหรือไม่
{
    char terminate_name[5][5] = {"end","exit"};
    int terminate_count=11,i=0;//ตัวนับทั้งหมดเท่ากับรายการ
    char buff[20];//ใช้เป็นตัวกลางในการพิจารณา
    strcpy(buff,str);//คัดลอกอินพุตไปใน buff เพื่อนำไปพิจารณา
    strlwr(buff);//เปลี่ยนทุกตัวอักษรเป็นพิมพ์เล็ก
    while (i<terminate_count&&strcmp(terminate_name[i], buff)!=0)//ขณะที่ตัวนับเริ่มต้นยังน้อยกว่าตัวนับทั้งหมด และ buff ยังไม่เหมือนกับรายการคำจบนั้นๆ
        i++;//เพิ่มตัวนับไปเรื่อยๆ
    if(i<terminate_count)//ถ้าตัวนับยังน้อยกว่าจำนวนรายการขณะที่พบ
        return 1;//รีเทิร์น 1
    else//มิฉะนั้น
        return 0;//รีเทิร์น 0
}
int main()
{
    int i,count,terminate;
    double n;
    char str[255],buff[255],token[40][20];
    //char str1[255] = " 1+2.3(7^8)sin + sin_e-2x+x2*2!/_x1 sine ";
    //char str2[255] = "SIN(cos(Tan(aSin(Acos(Atan) SQRT) log)exP)pow)";
    //char str3[255] = "+-*/^()2 3 .5 exit end 2$ 1A A1 sin2 2sin a@b 1.1. 1.1.1 ";
    do
    {
        printf("CMD > ");//แสดงผล CMD>
        gets(str);//รับสตริง
        printf("\"%s\"\n",str);//แสดงผลสตริงที่รับมา แล้วขึ้นบรรทัดใหม่
        strcpy(buff,str);//คัดลอกสตริงไป buff เพื่อนำไปพิจารณา
        strlwr(buff);//เปลี่ยนทุกตัวอักษรเป็นพิมพ์เล็ก
        add_space(buff);//เพิ่มช่องว่างระหว่าง Token
        while(buff[0]==' ')//ขณะที่สตริงแรกเป็นช่องว่าง
            for(int m=0;m<strlen(buff);m++)//วนรอบเท่าความยาว buff
                buff[m]=buff[m+1];//ย้ายสตริงที่ไม่ใช่ช่องว่างมาทับเพื่อตัดช่องว่างด้านหน้า
        while (buff[strlen(buff)-1]==' ')//ขณะที่สตริงก่อนสุดท้ายเป็นช่องว่าง
            buff[strlen(buff)-1] = '\0';//เปลี่ยนให้ตัวนั้นเป็นตัวสุดท้าย
        terminate = check_terminate(buff);
        if(terminate == 0)//ถ้าสตริงที่ป้อนมาเป็นendและexitหรือไม่เป็นทั้งคู่
        {
            printf("\"%s\"\n",buff);//แสดงผล buff และขึ้นบรรทัดใหม่
            count = split(buff,token);//ตัวนับเท่ากับจำนวน string ย่อย (เริ่มที่ 0)
            for(i=0;i<count;i++)//วนรอบเท่าจำนวน string ย่อย
            {
                if(check_number(token[i],&n)==1)//ถ้า string ย่อยตัวที่ i เป็น ตัวเลข
                    printf("token[%2d] : \"%s\" \t is number.\n",i,token[i]);//แสดงผล tokenตัวที่ i : " token นั้นๆ " \t is number.แล้วขึ้นบรรทัดใหม่
                else if(check_operator(token[i])==1)//ถ้า string ย่อยตัวที่ i เป็น ตัวดำเนินการ
                    printf("token[%2d] : \"%s\" \t is operator.\n",i,token[i]);//แสดงผล tokenตัวที่ i : " token นั้นๆ " \t is operator.แล้วขึ้นบรรทัดใหม่
                else if(check_function(token[i])==1)//ถ้า string ย่อยตัวที่ i เป็น ฟังก์ชัน
                    printf("token[%2d] : \"%s\" \t is fucntion.\n",i,token[i]);//แสดงผล tokenตัวที่ i : " token นั้นๆ " \t is function.แล้วขึ้นบรรทัดใหม่
                else if(check_identifier(token[i])==1)//ถ้า string ย่อยตัวที่ i เป็น ตัวบ่งชี้
                    printf("token[%2d] : \"%s\" \t is identifier.\n",i,token[i]);//แสดงผล tokenตัวที่ i : " token นั้นๆ " \t is identifier.แล้วขึ้นบรรทัดใหม่
                else//มิฉะนั้น
                    printf("token[%2d] : \"%s\" \t is error.\n",i,token[i]);//แสดงผล tokenตัวที่ i : " token นั้นๆ " \t is error.แล้วขึ้นบรรทัดใหม่
            }
        }
    } while(terminate == 0);//ทำไปเรื่อยๆ หากอินพุทไม่ใช่ end หรือ exit
    return 0;
}
