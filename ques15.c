
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10000


//declaring process structure
struct process
{
	int at; // arrival
	int bt;  // burst time 
	int pid;  // process id
	int ct;  // completion time
	int wt; // waiting time
	int tat; // turn around time 
	int b_temp;  // to hold the initial burst time
};

int main()
{
	int time,count = 0,min;
    double TotalWT=0;   //Total waiting time
    double TotalTAT=0;  //total turn around time
   

    int n,i; // n: no.of processes
    // i: iteration counter

    printf("\n\n\n\n -----------  | Question 15 : Priority Scheduling ( Shortest Remaining Time First : Pre-emptive ) |  -----------\n\n");
    printf("\n | Enter the number of processes  | :  ");
    scanf("%d",&n);

    //declaring process
    struct process p[n];

    //getting details for processes
    for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
        printf("\n | Enter The Arrival Time of Process P%d  | :  ",i+1);
		scanf("%d",&p[i].at);
		printf("\n | Enter The Burst Time of Process P%d  | : ",i+1);
		scanf("%d",&p[i].bt);
		
		//stroing burst time for future reference
		p[i].b_temp=p[i].bt;
		p[i].ct=0;
	}	
	
	
	system("cls");
	printf("\n\nProcessing...\n");

	//scheduling processes
	p[n].bt = MAX;
	time = 0;
	while(count != n)
	
    {
        min = n;
        for(i = 0; i < n; i++)
		{
            if(p[i].at <= time && p[i].bt < p[min].bt && p[i].bt > 0)
            {
                min = i;
            }
        }
        p[min].bt--;
        if(p[min].bt == 0)
        {
            count++;
            p[min].ct = time + 1;
        }
        time++;
    }
    
    // calculating waiting time and turn around time for processes
	 for(i=0;i<n;i++)
    {
    	p[i].tat = p[i].ct - p[i].at;
    	p[i].wt = p[i].tat -p[i].b_temp;
    	
    	TotalWT=TotalWT+p[i].wt;
    	TotalTAT=TotalTAT+p[i].tat;
    	
	}
	
	//displaying the final scenario
	printf("\nPROCESS_ID\t| Arrival_TIME  | Burst_Time\t|Completion_Time|Turn_Around_Time|Waiting_Time \n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t | %d\n",p[i].pid,p[i].at,p[i].b_temp,p[i].ct,p[i].tat,p[i].wt);
	}
	
	printf("\nTotal Waiting Time : %lf",TotalWT);
	printf("\nTotal TurnAround Time : %lf",TotalTAT);
	printf("\n------------------------------------");
	float average_wt=(TotalWT/n);
	float average_tat=(TotalTAT/n);
    printf("\n Average Waiting Time: %lf ", average_wt);
    printf("\n Average Turn-Around Time: %lf", average_tat);
    printf("\n------------------------------------");
	getch();
	return 0;
	
}
