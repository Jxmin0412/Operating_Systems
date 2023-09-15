#include <stdio.h>
void main()
{
    int bt[20], p[10], wt[20], tat[20], i, j, n, pos, temp;
    float wtavg, tatavg;
    printf("enter no. of processes ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter burst time of P%d:", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }
        //swap
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("process\tbursttime\twaitingtime\tturnaroundtime\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("avg wt time is %f\n", wtavg / n);
    printf("avg tat time is %f\n", tatavg / n);
}