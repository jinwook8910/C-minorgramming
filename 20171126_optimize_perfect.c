#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
    int ir1,ir2,ir3,ir4,ir5,ir6;
    int n;
    int cds;
    int cnt=0, finish = 0;

    int i;
    int j = 8;

    unsigned char dot1[8]={0x81,0x42,0x42,0x42,0x24,0x24,0x00,0x00};
    unsigned char dot[8]= { 0 };

    char keyboard;

    Open(szPort);

    while(1)
    {

        data = Sensor(1); //Sensor함수로 센서 값을 받는다. 1인 경우에는 IR센서 6개, 토크 센서 2개, 조도센서, 온도센서 값을 구조체에 넘겨준다.

        ir1 = data.IRSensor[0];
        ir2 = data.IRSensor[1];
        ir3 = data.IRSensor[2];
        ir4 = data.IRSensor[3];
        ir5 = data.IRSensor[4];
        ir6 = data.IRSensor[5];

       // ir1 = 0;

        printf("%d\n",ir1);

        cds = data.CDSSensor; // 조도센서

        if( ir1 > 550 && cnt == 0) //1번
        {
             cnt += 1;
        }

        if( ir2 > 550 && cnt == 1)
        {
             cnt += 1;
        }

        if( ir3 > 550 && cnt == 2)
        {
             cnt += 1;
        }

        if( ir4 > 550 && cnt == 3)
        {
             cnt += 1; //여기 들어오면 cnt가 4임
        }

        if( cnt == 4 )

        {
            Go(-200,-200);

            Sound(37);
            delay(300);
            Sound(37);
            delay(300);

            if( ir6 > 250)
            {
                Go(0,0);
                Sound(0);
                Display('s'); //대문자 인가?>>>>
                delay(2000);
                Display(0);

                cnt ++;
            }
        }


        if ( cnt == 5 ) //2번
        {

             Led(0x0010);
             delay(500);
             Led(0x0011);
             delay(500);

             Led(0x0013);
             delay(500);
             Led(0x0033);
             delay(500);

             Led(0x0000);

            while(1)
            {
                data = Sensor(1);
                ir1 = data.IRSensor[0];
                ir2 = data.IRSensor[1];
                ir3 = data.IRSensor[2];
                ir4 = data.IRSensor[3];
                ir5 = data.IRSensor[4];
                ir6 = data.IRSensor[5];

                cds = data.CDSSensor;

                printf("%d  %d  %d\n",ir1,ir2,ir3);

                if(ir1 > 200 && ir2 > 200 && ir3 > 200 && finish == 1) //4번
                {
                    Go(0,0);

                    for( i=0;i<3;i++)
                    {
                        Led(0x0033);
                        delay(500);
                        Led(0x0000);
                        delay(500);
                    }

                    for(i=0;i<2;i++)
                    {
                        Sound(37);
                        delay(500);
                        Sound(0);
                        delay(500);
                    }
                }
                else if( ir1 > 150 && ir2 > 150)
                {
                    Go(-400,-400);
                    Steering(1);
                }

                else if( ir2 > 150 && ir3 > 150)
                {
                    Go(-400,-400);
                    Steering(3);
                }

                else if( ir1 > 150 )
                {
                    Go(-400,-400);
                    Steering(1);

                }
                else if( ir3 > 150 )
                {
                    Go(-400,-400);
                    Steering(3);

                }



                else
                {
                    Go(300,300);
                    Steering(2);
                }


                if(cds < 50 && finish == 0) //3번
                {
                    Go(0,0);

                    for (i = 0; i < 8; i++)
                    {
                        dot[i] = (dot1[i] << j);
                    }

                        DisplayLine(dot[0],dot[1],dot[2],dot[3],dot[4],dot[5],dot[6],dot[7]);
                        delay(800);

                        j--;

                        if(j == 0) finish += 1;
                }
            }
            }
        }

        Close();
        return 0;
    }
