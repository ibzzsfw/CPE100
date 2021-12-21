//
//  63070501061
//  Assignment11
//
//  Created by suppakorn rakna on 12/11/2563 BE.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*Define Structure and def name*/
typedef struct grade_info
{
    long long id;
    char name[40];
    double mid, fnal, atten, total, gpoint;
    char grade[3];
}
/*as*/ student_data;

/*function declarations*/
char *strupr(char *buff);
/*
 *get string uppercase
 *use in searching
 *there's some problems of strupr in macOS
 */
int get_int_interval(int min, int max);                                                                                                                                                                                                                                                                                               /*get a integer                         */
double get_double_interval(double min, double max);                                                                                                                                                                                                                                                                                   /*get a double                          */
void Load_Student_File(student_data str[], int *strcount, char *file_check);                                                                                                                                                                                                                                                          /*open file to start using program      */
void print_data(student_data x);                                                                                                                                                                                                                                                                                                      /*display statistical data for a person */
int get_menu(void);                                                                                                                                                                                                                                                                                                                   /*get menu from user range 0 to 9       */
void search_score_in_range(student_data st[], int stcount);                                                                                                                                                                                                                                                                           /*search personal data by score         */
void set_grade(student_data st[], int stcount, int g_count[8], double *gpa_total, double A, double Bp, double B, double Cp, double C, double Dp, double D);                                                                                                                                                                           /*set grade by score                    */
void print_all_data(student_data st[], int count);                                                                                                                                                                                                                                                                                    /*print all data                        */
void search_name(student_data st[], int stcount);                                                                                                                                                                                                                                                                                     /*search part of name                   */
void search_grade(student_data st[], int stcount);                                                                                                                                                                                                                                                                                    /*search by specify grade               */
void sort_by_total(student_data st[], int stcount);                                                                                                                                                                                                                                                                                   /*sort data by total score and display  */
void sort_by_id(student_data st[], int stcount);                                                                                                                                                                                                                                                                                      /*sort by ID and display                */
void calculate(student_data st[], int stcount, double *min, double *max, double *mean, double *sd, double *min_mid, double *max_mid, double *mean_mid, double *sd_mid, double *min_fin, double *max_fin, double *mean_fin, double *sd_fin, double *min_atn, double *max_atn, double *mean_atn, double *sd_atn);                       /*calculate statistic                   */
void show_statistic(student_data st[], int stcount, double min, double max, double mean, double sd, double min_mid, double max_mid, double mean_mid, double sd_mid, double min_fin, double max_fin, double mean_fin, double sd_fin, double min_atn, double max_atn, double mean_atn, double sd_atn, double gpa_total, int g_count[]); /*show calculated statistic             */

int main()
{
    student_data st[100];
    int stcount = 0, menu;
    int g_count[8] = {0};
    double min = 0.0, max = 0.0, mean = 0.0, sd = 0.0;
    double min_mid = 0.0, max_mid = 0.0, mean_mid = 0.0, sd_mid = 0.0;
    double min_fin = 0.0, max_fin = 0.0, mean_fin = 0.0, sd_fin = 0.0;
    double min_atn = 0.0, max_atn = 0.0, mean_atn = 0.0, sd_atn = 0.0;
    double gpa_total = 0;
    char file_check = 'n', ch = '\0';
    double A, Bp, B, Cp, C, Dp, D;
    do
    {
        menu = get_menu(); /*get menufrom user*/
        if (menu == 1)     /*menu = 1?*/
        {
            Load_Student_File(st, &stcount, &file_check);  /*Load data*/
            calculate(st, stcount, &min, &max, &mean, &sd, /*Calculate*/
                      &min_mid, &max_mid, &mean_mid, &sd_mid,
                      &min_fin, &max_fin, &mean_fin, &sd_fin,
                      &min_atn, &max_atn, &mean_atn, &sd_atn);
            printf("\n\nPress any key to menu : ");
            scanf("%c", &ch);
            system("cls");
        }
        if (file_check == 'y') /*if already open file*/
        {
            if (menu == 2) /*menu = 2?*/
            {
                printf("Test case : ");
                scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf", &A, &Bp, &B, &Cp, &C, &Dp, &D); /*get indicate score to grading*/
                set_grade(st, stcount, g_count, &gpa_total, A, Bp, B, Cp, C, Dp, D); /*set grade by indicate score*/
                show_statistic(st, stcount, min, max, mean, sd,
                               min_mid, max_mid, mean_mid, sd_mid,
                               min_fin, max_fin, mean_fin, sd_fin,
                               min_atn, max_atn, mean_atn, sd_atn, gpa_total, g_count); /*show statistical data*/
            }
            if (menu == 3) /*menu = 3?*/
                show_statistic(st, stcount, min, max, mean, sd,
                               min_mid, max_mid, mean_mid, sd_mid,
                               min_fin, max_fin, mean_fin, sd_fin,
                               min_atn, max_atn, mean_atn, sd_atn, gpa_total, g_count); /*show statistical data*/
            if (menu == 4)                                                              /*menu = 4?*/
            {
                print_all_data(st, stcount); /*display all data in struct*/
                printf("\n\nPress any key to menu : ");
                scanf("%c", &ch);
                system("cls");
            }
            if (menu == 5)                          /*menu = 5?*/
                sort_by_total(st, stcount);         /*sort data by total score and then display data*/
            if (menu == 6)                          /*menu = 6?*/
                sort_by_id(st, stcount);            /*sort data by ID and then display data*/
            if (menu == 7)                          /*menu = 7?*/
                search_score_in_range(st, stcount); /*search score in range and display data*/
            if (menu == 8)                          /*menu = 8?*/
                search_grade(st, stcount);          /*search by grade and display*/
            if (menu == 9)                          /*menu = 9?*/
                search_name(st, stcount);           /*search by "part" of name and display*/
        }
        else /*there is no opened file*/
        {
            printf("\n Please read file before"); /*warning to read file*/
            printf("\n\nPress any key to menu : \n");
            scanf("%c", &ch);
            system("cls");
        }
    } while (menu != 0);
    return 0;
}

char *strupr(char *buff)
/*
 *get string uppercase
 *use in searching
 *there's some problems in macOS
 */
{
    unsigned char *p = (unsigned char *)buff;
    while (*p)
    {
        *p = toupper((unsigned char)*p);
        p++;
    }
    return buff;
}

int get_int_interval(int min, int max) /*get a integer*/
{
    int a;
    char ch;
    while (scanf("%d%c", &a, &ch) != 2 || ch != '\n' || (a < min) || (a > max)) /*check validation*/
    {
        rewind(stdin);
        printf("Error,please enter between %d-%d", min, max);
        printf("\nPlease input number again : ");
    }
    return a;
}

double get_double_interval(double min, double max) /*get a double*/
{
    double a;
    char ch;
    while (scanf("%lf%c", &a, &ch) != 2 || ch != '\n' || (a < min) || (a > max)) /*check validation*/
    {
        rewind(stdin);
        printf("Error,please enter between %lf-%lf", min, max);
        printf("\nPlease input number again : ");
    }
    return a;
}

void Load_Student_File(student_data str[], int *strcount, char *file_check) /*open file to start using program*/
{
    FILE *fp;
    student_data x;
    if ((fp = fopen("/Users/suppakornrakna/OneDrive - King Mongkut’s University of Technology Thonburi (KMUTT)/CPE100/Code/Assignment11/Assignment11/score.csv", "r")) != NULL) /*check can file open?*/
    {
        *strcount = 0;
        while (fscanf(fp, "%llu,%[^,],%lf,%lf,%lf", &x.id, x.name, &x.mid, &x.fnal, &x.atten) == 5)
        {
            x.total = x.mid + x.fnal + x.atten;
            str[(*strcount)++] = x;
        } /*contain data to array*/
        fclose(fp);
        printf("\nTotal read %d records.", *strcount);
        *file_check = 'y'; /*ordinary check*/
    }
    else
        printf("\nError Can't Read File score.csv\n");
}

void print_data(student_data x) /*display statistical data for a person*/
{
    printf("| %llu | %-40s | %5.1lf | %5.1lf | %5.1lf | %5.1lf |   %-3s | %2.1lf |\n", x.id, x.name, x.mid, x.fnal, x.atten, x.total, x.grade, x.gpoint);
}

int get_menu() /*get menu from user range 0 to 9*/
{
    int select;
    printf("\n=================================================\n");
    printf("*                     Function                  *\n");
    printf("=================================================\n");
    printf("*  1. Read File & Calulate                      *\n");
    printf("*  2. Set grade                                 *\n");
    printf("*  3. Show statistic                            *\n");
    printf("*  4. Show Data                                 *\n");
    printf("*  5. Sort By Total Score                       *\n");
    printf("*  6. Sort By ID                                *\n");
    printf("*  7. Search By Score                           *\n");
    printf("*  8. Search By Grade                           *\n");
    printf("*  9. Search By Name                            *\n");
    printf("*  0. Exit program                              *\n");
    printf("=================================================\n");
    printf("Enter menu number = ");
    select = get_int_interval(0, 9); /*get from user*/
    return select;
}

void search_score_in_range(student_data st[], int stcount) /*search personal data by score*/
{
    char ch = '\0';
    do
    {
        double min, max;
        int i, check_count = 0;
        printf(" Enter Range of min score  and max score "); /*asking for range of score*/
        printf("\n Enter Min :  ");
        min = get_double_interval(0, 100);
        printf(" Enter Max :  ");
        max = get_double_interval(min, 100);
        printf("\n   ========================================================================================================");
        printf("\n   |     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
        printf("\n   ========================================================================================================\n");
        for (i = 0; i < stcount; i++)
            if (st[i].total >= min && st[i].total <= max) /*scope*/
            {
                printf("%2d.", check_count + 1);
                print_data(st[i]); /*print data*/
                check_count++;
            }
        if (check_count == 0)
            printf("There is no data\n ");
        printf("   ========================================================================================================");
        printf("\n\nPress Y to search again : ");
        scanf("%c", &ch);
        system("cls");
    } while (ch == 'y' || ch == 'Y');
}

void set_grade(student_data st[], int stcount, int g_count[8], double *gpa_total, double A, double Bp, double B, double Cp, double C, double Dp, double D) /*set grade by score*/
{
    for (int i = 0; i < stcount; i++) /*set grade and count grade*/
    {
        if (st[i].total >= A)
        {
            strcpy(st[i].grade, "A");
            st[i].gpoint = 4.0;
            g_count[0]++;
        }
        else if (st[i].total >= Bp)
        {
            strcpy(st[i].grade, "B+");
            st[i].gpoint = 3.5;
            g_count[1]++;
        }
        else if (st[i].total >= B)
        {
            strcpy(st[i].grade, "B");
            st[i].gpoint = 3;
            g_count[2]++;
        }
        else if (st[i].total >= Cp)
        {
            strcpy(st[i].grade, "C+");
            st[i].gpoint = 2.5;
            g_count[3]++;
        }
        else if (st[i].total >= C)
        {
            strcpy(st[i].grade, "C");
            st[i].gpoint = 2;
            g_count[4]++;
        }
        else if (st[i].total >= Dp)
        {
            strcpy(st[i].grade, "D+");
            st[i].gpoint = 1.5;
            g_count[5]++;
        }
        else if (st[i].total >= D)
        {
            strcpy(st[i].grade, "D");
            st[i].gpoint = 1;
            g_count[6]++;
        }
        else
        {
            strcpy(st[i].grade, "F");
            st[i].gpoint = 0;
            g_count[7]++;
        }
        *gpa_total = *gpa_total + st[i].gpoint; /*sum gpa*/
    }
    *gpa_total = *gpa_total / stcount; /*calculate mean of gpa*/
}

void print_all_data(student_data st[], int stcount) /*print all data*/
{
    if (stcount > 0) /*there is student data*/
    {
        printf("\n   ========================================================================================================");
        printf("\n   |     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
        printf("\n   ========================================================================================================\n");
        for (int i = 0; i < stcount; i++)
        {
            printf("%2d.", i + 1);
            print_data(st[i]); /*print data*/
        }
        printf("   ========================================================================================================");
    }
    else /*there is no student data*/
        printf("\nThere is no data.");
}

void search_name(student_data st[], int stcount) /*search part of name*/
{
    char key[16];
    int i;
    do
    {
        int check_count = 0;
        printf("\n Enter Search key (0 = Exit)  : ");
        scanf("%15s", key); /*input part of name*/
        strupr(key);
        if (strcmp(key, "0") != 0)
        {
            printf("\n   ========================================================================================================");
            printf("\n   |     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
            printf("\n   ========================================================================================================\n");
            for (i = 0; i < stcount; i++)
                if (strstr(st[i].name, key) != NULL) /*found*/
                {
                    printf("%2d.", check_count + 1);
                    print_data(st[i]); /*print data*/
                    check_count++;
                }
            if (check_count == 0)
                printf("there is no data\n");
            printf("   ========================================================================================================");
        }
    } while (strcmp(key, "0") != 0);
    system("cls");
}

void search_grade(student_data st[], int stcount) /*search by specify grade*/
{
    char key[3];
    int i, count;
    do
    {
        int check_count = 0;
        printf("\n Search Grade (A, B+, B, C+, C, D+, D, F (0 = Exit) ");
        scanf("%2s", key); /*input grade*/
        count = 0;
        strupr(key);
        if (strcmp(key, "0") != 0)
            printf("\n   ========================================================================================================");
        printf("\n   |     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
        printf("\n   ========================================================================================================\n");
        for (i = 0; i < stcount; i++)
            if (strcmp(st[i].grade, key) == 0) /*found*/
            {
                printf("%2d.", check_count + 1);
                print_data(st[i]); /*print data*/
                check_count++;
            }
        if (check_count == 0)
            printf("there is no data\n");
        printf("   ========================================================================================================");
    } while (strcmp(key, "0") != 0);
    system("cls");
}

void sort_by_total(student_data st[], int stcount) /*sort data by total score and display*/
{
    int i, j;
    char ch;
    student_data x;
    for (i = 0; i < stcount - 1; i++)      /*for first element*/
        for (j = i + 1; j < stcount; j++)  /*for compare element*/
            if (st[j].total > st[i].total) /*compare to sort*/
            {                              /*swap data*/
                x = st[i];
                st[i] = st[j];
                st[j] = x;
            }
    print_all_data(st, stcount); /*print all data*/
    printf("\n\nPress any key to menu : ");
    scanf("%c", &ch);
    system("cls");
}

void sort_by_id(student_data st[], int stcount) /*sort by ID and display*/
{
    int i, j;
    char ch;
    student_data x;
    for (i = 0; i < stcount - 1; i++)     /*for first element*/
        for (j = i + 1; j < stcount; j++) /*for compare element*/
            if (st[j].id < st[i].id)      /*compare to sort*/
            {                             /*swap data*/
                x = st[i];
                st[i] = st[j];
                st[j] = x;
            }
    print_all_data(st, stcount); /*print all data*/
    printf("\n\nPress any key to menu : ");
    scanf("%c", &ch);
    system("cls");
}

void calculate(student_data st[], int stcount, double *min, double *max, double *mean, double *sd, double *min_mid, double *max_mid, double *mean_mid, double *sd_mid, double *min_fin, double *max_fin, double *mean_fin, double *sd_fin, double *min_atn, double *max_atn, double *mean_atn, double *sd_atn) /*calculate statistic*/
{
    int i;
    double sum = 0, sumsqr = 0;
    double sum_mid = 0, sumsqr_mid = 0;
    double sum_fin = 0, sumsqr_fin = 0;
    double sum_atn = 0, sumsqr_atn = 0;
    *min = *max = st[0].total;
    *min_mid = *max_mid = st[0].mid;
    *min_fin = *max_fin = st[0].fnal;
    *min_atn = *max_atn = st[0].atten;
    /*for score table*/
    /*min max sums*/
    for (i = 0; i < stcount; i++)
    {
        if (st[i].total < *min)
            *min = st[i].total;
        if (st[i].total > *max)
            *max = st[i].total;
        sum = sum + st[i].total;
        sumsqr = sumsqr + pow(st[i].total, 2);
    }
    for (i = 0; i < stcount; i++)
    {
        if (st[i].mid < *min_mid)
            *min_mid = st[i].mid;
        if (st[i].mid > *max_mid)
            *max_mid = st[i].mid;
        sum_mid = sum_mid + st[i].mid;
        sumsqr_mid = sumsqr_mid + pow(st[i].mid, 2);
    }
    for (i = 0; i < stcount; i++)
    {
        if (st[i].fnal < *min_fin)
            *min_fin = st[i].fnal;
        if (st[i].fnal > *max_fin)
            *max_fin = st[i].fnal;
        sum_fin = sum_fin + st[i].fnal;
        sumsqr_fin = sumsqr_fin + pow(st[i].fnal, 2);
    }
    for (i = 0; i < stcount; i++)
    {
        if (st[i].atten < *min_atn)
            *min_atn = st[i].atten;
        if (st[i].atten > *max_atn)
            *max_atn = st[i].atten;
        sum_atn = sum_atn + st[i].atten;
        sumsqr_atn = sumsqr_atn + pow(st[i].atten, 2);
    }
    /*mean sd*/
    *mean = sum / stcount;
    *mean_mid = sum_mid / stcount;
    *mean_fin = sum_fin / stcount;
    *mean_atn = sum_atn / stcount;
    *sd = sqrt(((sumsqr / stcount) - pow(*mean, 2)));
    *sd_mid = sqrt((sumsqr_mid / stcount) - pow(*mean_mid, 2));
    *sd_fin = sqrt((sumsqr_fin / stcount) - pow(*mean_fin, 2));
    *sd_atn = sqrt((sumsqr_atn / stcount) - pow(*mean_atn, 2));
}

void show_statistic(student_data st[], int stcount, double min, double max, double mean, double sd, double min_mid, double max_mid, double mean_mid, double sd_mid, double min_fin, double max_fin, double mean_fin, double sd_fin, double min_atn, double max_atn, double mean_atn, double sd_atn, double gpa_total, int g_count[]) /*show calculated statistic*/
{
    char ch;
    calculate(st, stcount, &min, &max, &mean, &sd, &min_mid, &max_mid, &mean_mid, &sd_mid, &min_fin, &max_fin, &mean_fin, &sd_fin, &min_atn, &max_atn, &mean_atn, &sd_atn);
    /*score table*/
    printf("\n==================================================");
    printf("\n|  Score |   Mid   |  Final  |  Atten  |  Total  |");
    printf("\n==================================================");
    printf("\n|  Min   |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |", min_mid, min_fin, min_atn, min);
    printf("\n|  Max   |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |", max_mid, max_fin, max_atn, max);
    printf("\n|  Mean  |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |", mean_mid, mean_fin, mean_atn, mean);
    printf("\n|  SD    |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |", sd_mid, sd_fin, sd_atn, sd);
    printf("\n==================================================");
    /*grade count table*/
    printf("\n====================");
    printf("\n| GRADE | A  | %3d | ", g_count[0]);
    printf("\n| GRADE | B+ | %3d | ", g_count[1]);
    printf("\n| GRADE | B  | %3d | ", g_count[2]);
    printf("\n| GRADE | C+ | %3d | ", g_count[3]);
    printf("\n| GRADE | C  | %3d | ", g_count[4]);
    printf("\n| GRADE | D+ | %3d | ", g_count[5]);
    printf("\n| GRADE | D  | %3d | ", g_count[6]);
    printf("\n| GRADE | F  | %3d | ", g_count[7]);
    printf("\n====================");
    printf("\n\nGPA = %.2lf", gpa_total);
    printf("\n\nPress any key to menu : ");
    scanf("%c", &ch);
    system("cls");
}
