#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
    int ir1,ir2,ir3,ir4;
    int cds;
    open(szPort);


    while(1)
    {
        data = Sensor(1);
        ir1 = data.IRSensor[0];
        ir2 = data.IRSensor[1];
        ir3 = data.IRSensor[2];
        cds=data.CDSSensor;

        if(cds < 150)
        {
            Go(0,0);
            Steering(2);

            Display('K');
            delay(500);
            Display('M');
            delay(500);
            Display('S');
            delay(500);

            DisplayLine(0,0,0,0,0,0,0,0);
            delay(500);
        }

        if(ir1>15 && ir2>15 &&ir3>15)
        {
            Go(-350,-350);
            Steering(1);
        }
        else if(ir1>15 && ir2>15)
        {
            Go(-350,-350);
            Steering(1);
        }
        else if(ir1>15)
        {
            Go(-350,-350);
            Steering(1);
        }

        else if(ir2>15 && ir3>15)
        {
            Go(-350,-350);
            steering(3);
        }
        else if(ir3>15)
        {
            Go(-350,-350);
            steering(3);
        }
        else
        {
            Go(350,350);
            Steering(2);
        }
    }

    Close();
    return 0;
}
