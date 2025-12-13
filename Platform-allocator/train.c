#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Global variables
int n_trains,n_plat;
int i,j;

//Strecture for platforms
typedef struct
{
    int index;
    bool empty;
}platforms;

//Strecture for trains
typedef struct
{
    int id;
    int a_time;
    int d_time;
    int pn;
    bool left;
}trains;

//Function to get details about n_trains and n_platforms
void getdata();

//Function to start simulation
void simulate();

void main()
{
    getdata();
    simulate();
    getch();
}

void getdata()
{
    printf("=0=0=0=Welcome to Platfrom simulator=0=0=0=\n");
    printf("\nEnter the total number of platforms:");
    scanf("%d",&n_plat);
    if(n_plat<=0 || n_plat>100)
    {
        printf("Invalied platform number!!");
        getch();
        exit(0);
    }
    printf("Enter the total number of trains arriving:");
    scanf("%d",&n_trains);
    if(n_trains<=0 || n_trains>100)
    {
        printf("Invalied train number!!");
        getch();
        exit(0);
    }
}

void simulate()
{
    platforms platform[n_plat];
    trains train[n_trains];
    for(i=0;i<n_trains;i++)
    {
        printf("\nEnter ID of train %d:",i+1);
        scanf("%d",&train[i].id);
        int h,m;
        printf("Enter arrival time (hh mm):");
        scanf("%d %d",&h,&m);
        h+=(h*60)+m;
        train[i].a_time=h;
        printf("Enter departure time (hh mm):");
        scanf("%d %d",&h,&m);
        h+=(h*60)+m;
        train[i].d_time=h;
        if(train[i].d_time-train[i].a_time<=0)
        {
            printf("Invalied timings!");
            getch();
            exit(0);
        }
        train[i].left=false;
        train[i].pn=-1;
    }
    printf("\nAll set. Press any key to start the simulation");
    getch();
    system("cls");
    printf("=0=0=0=Welcome to Platfrom simulator=0=0=0=\n");
}