#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
    int ir1,ir2,ir3,ir4;
    int n;
    Open(szPort);

    while(1){
        scanf("%d",&n);
        if(n==1)
        {
            Go(500,500);
            Steering(2);
            delay(500);
        }
        else if(n==2)
        {
            Go(0,0);
            Steering(2);
        }
        else if(n=3)
        {
            break;
        }
    }
    Close();

    return 0;
}
