#include<stdio.h>
int getMax(int arr[],int z)
{
    for (int i = 1; i < z; ++i) 
    {
        if (arr[0] < arr[i]) 
        {
        arr[0] = arr[i];
        }
    }
    return arr[0];
}
void main()
{
    printf("Enter the number of operations\n");
    int n;
    int opct=0;
    scanf("%d",&n);
    int operations[n][1];
    int top = 0;
    int op[n];
    int stack[n];
    for(int i = 0;i<n;i++)
    {
        printf("\nEnter the query\n");
        int x;
    valid:
        scanf("%d",&x);
        operations[i][0]=x;
        if (x==1)
        {
            printf("Enter the element to be pushed : ");
            int tmp;
            scanf("%d", &tmp);
            stack[top]=tmp;
            top++;
        }
        else if(x==2)
        {
            stack[top]=" ";
            top--;
        }
        else if (x==3)
        {
            op[opct]=getMax(stack,n);
            opct++;
        }
        else
        {
            printf("\nNot a valid Query, Please re-enter\n");
            goto valid;
        }
    }
    for (int i = 0; op[i]!=' '; i++)
    {
        printf("\n%d",op[i]);
    }
}
