#include <stdio.h>
void main()
{
    int pr[20], bt[20], p[10], wt[20], tat[20], i, j, n, pos, temp;
    float wtavg, tatavg;
    printf("enter no. of processes ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter burst time of P%d:", i);
        scanf("%d", &bt[i]);
        printf("enter priority of P%d:", i);
        scanf("%d", &pr[i]);
        p[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
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
    printf("process\t\tpriority\t\tbursttime\t\twaitingtime\t\tturnaroundtime\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }
    printf("avg wt time is %f\n", wtavg / n);
    printf("avg tat time is %f\n", tatavg / n);
}