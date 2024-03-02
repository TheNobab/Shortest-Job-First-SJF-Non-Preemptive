//Shortest Job First (SJF)without arrival time Non Preemptive
#include<stdio.h>

int main(){
    int n=0,i=0,j,pid[15],bt[15],ct[15],wt[15],tat[15],temp;
    printf("# Shortest Job First (SJF)without arrival time Non Preemptive \n#");
    printf("How many process: ");
    scanf("%d",&n);


    for(i=0;i<n;i++){
        printf("Process No: ");
        scanf("%d",&pid[i]);
        printf("process %d brust time: ",pid[i]);
        scanf("%d",&bt[i]);
        printf("\n");
    }
//buble sort the burst array accending
for(i=0;i<n;i++){
    for(j=1+i;j<n;j++){
            if(bt[j]<=bt[i]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }

    }
}
// Completion Time
    ct[0] = bt[0];//first process burst is the completion time.
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];//previous completion time sum burst time.
    }
//Turn Around Time = Completion Time – Arrival Time.
for(i=0;i<n;i++){
        tat[i]=ct[i];//because there have no arrival time .

}
//Waiting Time = Turn Around Time – Burst Time.
for(i=0;i<n;i++){
    wt[i]=tat[i]-bt[i];
}
//Showing output on tarminal
    printf("process number\t burst time\t completion time\t turn around time\twaiting time\n");
    for(i=0;i<n;i++){
    printf("%d\t\t %d\t\t\t %d\t\t %d\t\t\t  %d\n",pid[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
