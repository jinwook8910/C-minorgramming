#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
     int ir1, ir2, ir3, ir4;

    open(szPort);
    Go(0,0);
    while(1)
    {
        data = Sensor(1);
        ir1 = data.IRSensor[0];
        ir2 = data.IRSensor[1];
        ir3 = data.IRSensor[2];
        ir4 = data.IRSensor[3];

        if( ir4 > 600)
        {
            Go(500,500);
        }
        else
        {
            Go(0,0);
        {

    {
     Close();
     return 0 ;
}
