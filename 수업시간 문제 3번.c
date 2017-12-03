#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
    int ir1,ir2,ir3,ir4;
    int cds = data.CDSSensor;
    int cnt = 0;
    int light = 0;
    Open(szPort);


    while(1)
    {
        data = Sensor(1);
        ir1 = data.IRSensor[0];
        ir2 = data.IRSensor[1];
        ir3 = data.IRSensor[2];
        cds = data.CDSSensor;


        if( cds < 150 && light == 0 )
        {
            Go(0,0);
            Steering(2);
        }


        else if(ir1>40 && ir2>40 &&cnt == 0)
        {
            Go(-400,-300);
            Steering(1);
            light += 1;
        }
        else if(ir1>40 &&cnt == 0)
        {
            Go(-400,-300);
            Steering(1);
            light += 1;
        }



        else if( cds < 150 && light >0 &&cnt ==0 )
        {
            Steering(2);

            Go(0,0);

            Display('K');
            delay(500);
            Display('M');
            delay(500);
            Display('S');
            delay(500);

            DisplayLine(0,0,0,0,0,0,0,0);
            delay(500);

            Go(400,300);
            delay(500);






            cnt += 1;
        }


       else if(ir2>150 &&cnt >= 1 && ir3 >100 && ir1 < 20)
        {

             Go(0,0);

           DisplayLine(0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff);
           delay(500);
            Led(0xC0FF);
            delay(500);

           Sound(37);
           delay(500);
           Sound(37);
           delay(500);

           break;

        }

        else
        {
            Steering(2);
            Go(400,320);

        }

    }

    Close();
    return 0;
}
