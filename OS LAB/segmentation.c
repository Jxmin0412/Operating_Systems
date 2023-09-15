#include <stdio.h>
int main()
{
    int segTable[10][2], NumSeg, baseAdd, Size, offset, SegNo, phyAdd;
    int i;

    printf("Enter the number of Segments of process 1\n");
    scanf("%d", &NumSeg);

    // Build the segment segTable
    for (i = 0; i < NumSeg; i++)
    {
        printf("Enter the Size(Limit value) and BaseAddress of the segment%d \n:", i);
        scanf("%d%d", &segTable[i][0], &segTable[i][1]);
    }
    printf("Following is the segment Table entered by the user \n");
    printf("SegNo Limit value Base Address\n");
    for (i = 0; i < NumSeg; i++)
    {
        printf("%d %d %d", i, segTable[i][0], segTable[i][1]);
        printf("\n");
    }

    while (1)
    {
        printf("Enter the Logical Address : (Segment No and Offset value) \n");
        scanf("%d%d", &SegNo, &offset);

        if (SegNo > NumSeg)
        {
            printf("Wrong segment No so Address binding not possible\n");
        }
        else if (offset > segTable[SegNo][0])
        {
            printf("offset value is greater than the limit so Address binding not possible \n");
        }
        else
        {
            phyAdd = segTable[SegNo][1] + offset;
            printf("Base Address for the given Segment Number is %d\n", segTable[SegNo][1]);
            printf("Physical address for the give Logical Adress is %d\n", phyAdd);
        }
    }
    return 0;
}