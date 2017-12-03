#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    Open(szPort);

    char keyboard;

    while(1)
    {
        scanf("%c",&keyboard);

        switch(keyboard)
        {
        case 'w':
            Go(500,500);
            Steering(2);
             delay(500);
            break;

        case 'a':
            Go(500,500);
            Steering(1);
             delay(500);
            break;

        case 'd':
            Go(500,500);
            Steering(3);
             delay(500);
            break;

        case 'x':
            Go(-500,-500);
            Steering(2);
             delay(500);
            break;

            case 's':
            Go(0,0);
            Steering(2);
             delay(500);
            break;

        }
    }

    Close();
    return 0;
}
