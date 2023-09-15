#include <stdio.h>
void main()
{
    int i, n, bt[20], wt[20], tat[20];
    float wtavg, tatavg;
    printf("enter no. of processes ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter burst time for process %d:", i);
        scanf("%d", &bt[i]);
    }
    // Step-1:For first process
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    // Step-2:For remaining processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    // Displaying the result
    printf("process\tbursttime\twaitingtime\tturnaroundtime\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    printf("avg wt time is %f\n", wtavg / n);
    printf("avg tat time is %f\n", tatavg / n);
}
