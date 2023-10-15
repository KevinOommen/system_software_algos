#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct p{
    int pid;
    int wt;
    int bt;
    int at;
    int tat;
    int ct;

}process[SIZE];


void sortby_at(int n){
    int i,j;
    struct p temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if(process[j].at>process[j+1].at){
                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
        
    }
    
}
//driver
int main(){
    int n;
    int i;
    double ttat,twt,avgtat,avgwt;

    printf("Enter n <= %d:",SIZE);
    scanf("%d",&n);
    if(n>SIZE)
        exit(0);

    for(i=0;i<n;i++){
        process[i].pid=i+1;
        printf("Enter burst time of process %d: ",(i+1));
        scanf("%d",&process[i].bt);
        printf("Enter arrival time of process %d: ",(i+1));
        scanf("%d",&process[i].at);  
    }
    
    sortby_at(n);
    process[0].wt=0;
    process[0].tat=process[0].bt;
    process[0].ct=process[0].bt;
    
    for ( i = 1; i < n; i++)
    {
        process[i].wt=((process[i-1].ct-process[i].at)>=0)? process[i-1].ct-process[i].at:0;
        process[i].ct=process[i].at+process[i].bt+process[i].wt;
        process[i].tat=process[i].ct-process[i].at;
        
    }
    for ( i = 0; i < n; i++)
    {
        ttat+=process[i].tat;
        twt+=process[i].wt;    
    }
    
    avgtat=ttat/n;
    avgwt=twt/n;

    printf("FCFS schedule\n");
    printf("PID\t\tArrivalTime\t\tBursttime\t\tWaitingT\tTAT\tCompTime\n");
    //printf("**************************\t\t**************************\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].at,process[i].bt,process[i].wt,process[i].tat,process[i].ct);
    }
    printf("Avg turanaround time=%lf",avgtat);  
    printf("Avg waiting time=%lf",avgwt);
    printf("Total turnaround time=%lf",ttat);
    printf("Total waiting time=%lf",twt);   
}