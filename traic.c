#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
int i,j;
typedef struct train
{
    int id;
    int a_time;
    int d_time;
    int p_no;
    bool wait;
}train;

typedef struct platform
{
    int t_id;
    bool is_empty;
}platform;

void simulate()
{
    printf("=0=0=0=AUTOMATIC TRAIN PLATFORM ALLOCATION STYTEM=0=0=0=\n");
    printf("\nEnter the number total number of trains coming:");
    int n=0;
    scanf("%d",&n);
    printf("Enter total number of platforms available in the station:");
    int m;
    scanf("%d",&m);
    train trains[n];
    printf("Enter the train details:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter train %d ID:",i+1);
        scanf("%d",&trains[i].id);
        printf("Enter arraival time (hh:mm):");
        int h,min;
        scanf("%d %d",&h,&min);
        trains[i].a_time=(h*60)+min;
        printf("Enter departure time (hh:mm):");
        scanf("%d %d",&h,&min);
        trains[i].d_time=(h*60)+min;
        if(trains[i].d_time<=trains[i].a_time || trains[i].a_time==0 || trains[i].d_time==0)
        {
            printf("Invalied timing!!");
            exit(0);
        }
        trains[i].p_no=-1;
        trains[i].wait=false;
    }

    //set platforms
    platform platforms[m];
    for(i=0;i<m;i++)
    {
        platforms[i].t_id=-1;
        platforms[i].is_empty=true;
    }

    //sorting trains using therir arrival time
    for(i=0;i<n;i++)
    {
        train trmp;
        for(j=i+1;j<n;j++)
        {
            if(trains[i].a_time>trains[j].a_time)
            {
                trmp=trains[i];
                trains[i]=trains[j];
                trains[j]=trmp;
            }
        }
    }

    //Start time and end time
    int s_time=trains[0].a_time;
    int e_time=trains[0].d_time;

    for(i=0;i<n;i++)
    {
        if(trains[i].d_time>e_time)
        {
            e_time=trains[i].d_time;
        }
    }

    printf("\nPress any key to start simulation");
    getch();
    //Simulation starts
    for(int t=s_time;t<=e_time;t++)
    {
        system("cls");
        printf("\n=0=0=0=AUTOMATIC TRAIN PLATFORM ALLOCATION STYTEM=0=0=0=\n");
        int ch=t/60;
        int cm=t%60;
        printf("\nCurrnet time:%2d:%2d\n",ch,cm);
        for(i=0;i<n;i++)
        {
            if(trains[i].d_time==t)
            {
                platforms[trains[i].p_no].t_id=-1;
                platforms[trains[i].p_no].is_empty=true;
                trains[i].p_no=-1;
                trains[i].wait=false;
            }
            if(trains[i].a_time==t)
            {
                for(j=0;j<m;j++)
                {
                    if(platforms[j].is_empty)
                    {
                        trains[i].p_no=j;
                        platforms[j].t_id=i;
                        platforms[j].is_empty=false;
                        trains[i].wait=true;
                        break;
                    }
                }
            }
        }
        printf("Id     A_time   d_time   p_no   status");
        printf("\n------------------------------------------------------");
        for(i=0;i<n;i++)
        {
            printf("\n%d     ",trains[i].id);
            int h=trains[i].a_time/60;
            int M=trains[i].a_time%60;
            printf("%2d:%2d    ",h,M);
            h=trains[i].d_time/60;
            M=trains[i].d_time%60;
            printf("%2d:%2d    ",h,M);
            if(trains[i].p_no!=-1)
            {
                printf("%d",trains[i].p_no+1);
            }
            else
            {
                printf("NA");
            }

            if(trains[i].wait)
            {
                printf("    Arrived");
            }
            else if(trains[i].d_time<t+3 && !trains[i].wait)
            {
                printf("     Left");
            }
            else if(trains[i].a_time>t && !trains[i].wait)
            {
                printf("   Not arrived");
            }
        }
        Sleep(1500);
    }
    printf("\n");
    printf("\nSIMULATION ENDED SUCCESSFULLY!\nPress any key to exit\n");
    getch();
}
void main()
{
    simulate();
}