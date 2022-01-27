#include<stdio.h>
void main()
{
    printf("Enter the Number of customers : ");
    int TTotal=0;                   //Sum of all waiting time for all customers
    int N;                          //No. of Customers
    scanf ("%d",&N);                  
    int IO[N][2];                   //Array to store in-time and out time of customers
    int T[N];                       //Time of order placed by ith customer
    int L[N];                       //Time to cook the pan
    printf("\nEnter T0 : ");
    scanf("%d",&T[0]);
    printf("\nEnter L0 : ");
    scanf("%d",&L[0]);
    for (int  i = 1; i < N; i++)    //Taking input for T[] and L[]
    {
        printf("\nEnter T%d : ", i);
        scanf("%d",&T[i]);
        printf("\nEnter L%d : ", i);
        scanf("%d",&L[i]);
    }
    IO[0][0]=T[0];                  //In time of 1st customer
    IO[0][1]=T[0] + L[0];           //Out time of 1st customer
    int TCurrent =T[0] + L[0];      
    for (int k = 1; k < N; k++)
    {
        int Lmin;
        int Tmin;
        for (int i = 1; i < N; i++) //Loop to find which pan to cook next
        {
        int posmin= -1;
        Tmin= T[i];
        Lmin=L[i];
        for (int j=1;j<N;j++)
        { 
            if(T[j]<TCurrent)       //If a pan is ordered while the previous one is cooking
            {
                if(L[j]<Lmin)
                {
                    Lmin=L[j];
                    Tmin = T[j];
                    posmin = j;
                }
            }
        }
        if (posmin==-1)             //If a pan is ordered after the previous one is already cooked
        {
            for (int j = 1; j < N; j++)
            {
                if (T[j]<Tmin)
                {
                    Tmin=T[j];
                    Lmin =L[j];
                    posmin=j;
                    for (int l = 1; l < N; l++)
                    {
                        if(Tmin==T[l])
                        {
                            if(L[l]<Lmin)
                            {
                                Lmin=L[l];
                                posmin=l;
                            }
                        }
                    }  
                }
            }  
        }
        TCurrent = TCurrent + Lmin;
        T[posmin]=9999;
        L[posmin]=9999;
        break;
        }
        IO[k][0]=Tmin;
        IO[k][1]=IO[k-1][1]+Lmin;
        //printf("\n%d  %d",IO[k][0],IO[k][1] ); 
    }
    for (int i = 0; i < N; i++)
    {
        TTotal=TTotal + IO[i][1]-IO[i][0];
    }
    int TAvg = TTotal/N;
    printf("\nMinimum Average Waiting Time : %d",TAvg);
}
