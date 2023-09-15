#include <stdio.h>
void main()
{
    int i, j, n, bt[10], wt[10], tat[10], t, ct[10], max;
    float wtavg, tatavg, temp = 0;
    printf("enter no. of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("burst time of P%d:", i);
        scanf("%d", &bt[i]);
        ct[i] = bt[i];
    }
    printf("enter quantum time:");
    scanf("%d", &t);
    max = bt[0];
    for (i = 1; i < n; i++)
    {
        if (max < bt[i])
            max = bt[i];
    }
    for (j = 0; j < (max / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (bt[i] != 0)
            {
                if (bt[i] <= t)
                {
                    tat[i] = temp + bt[i];
                    temp = temp + bt[i];
                    bt[i] = 0;
                }
                else
                {
                    bt[i] = bt[i] - t;
                    temp = temp + t;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - ct[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("process\t\tbursttime\t\twaitingtime\tturnaroundtime\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, ct[i], wt[i], tat[i]);
    }
    printf("avg wt time is %f\n", wtavg / n);
    printf("avg tat time is %f\n", tatavg / n);
}