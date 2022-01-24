#include<stdio.h>
void printArr(int arr[],int sz)
{
    for(int i=0;i<sz;i++)
    {      
        printf("%d ", arr[i]);
    }
}
void main()
{
    int Q;
    printf("Enter size of Array: ");
    scanf("%d", &Q);
    int P[Q];
    
    for(int i=0;i<Q;i++)
    {
        printf("Enter the Elements: ");
        scanf("%d", &P[i]);
    }
    printf("Original Array:\n");
    printArr(P,Q);
    int R[Q];
    int T=Q;
    for(int i=0;i<Q;i++)
    {
        R[i]=P[T-1];
        T--;
    }
    printf("\n Reversed Array:\n");
    printArr(R,Q);
}
