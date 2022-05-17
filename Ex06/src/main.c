/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

#define DELAY_COUNTER 200000000

static const char * taskOneMessage = "I am task 01";
static const char * taskTwoMessage = "I am task 02 and I am Green!!";

void vTaskFunction(void *pvParameters);

int main(void)
{
    xTaskCreate(vTaskFunction, "Task 1", 1024, (void *)taskOneMessage, 2, NULL);
    xTaskCreate(vTaskFunction, "Task 2", 1024, (void *)taskTwoMessage, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

void vTaskFunction(void *pvParameters)
{
    char *pcTaskName;
    TickType_t xLastWakeTime;
    TickType_t xCurrentTickTime;
    TickType_t xTaskPeriod;

    pcTaskName = (char *) pvParameters;

    xTaskPeriod = pdMS_TO_TICKS(1000);//ms

    float ticksRatio = (1/((float)configTICK_RATE_HZ));

    xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        if(strcmp(pcTaskName,taskOneMessage) == 0){
            printf("\033[0;31m%s and I was wake at %.2f[s]\033[0m ", 
                            pcTaskName, 
                            xLastWakeTime*ticksRatio);
            for(uint64_t i=0; i<250000000;i++){}
        }else{
            printf("\033[0;32m%s\033[0m ", pcTaskName);
            for(uint64_t i=0; i<000000;i++){}
        }
        

        xCurrentTickTime = xTaskGetTickCount();
        float timeSpent = (xCurrentTickTime - xLastWakeTime)*ticksRatio;
        printf("\033[0;96mI've spent %0.2f seconds of your life!\033[0m\n", 
                timeSpent);
        vTaskDelayUntil(&xLastWakeTime, xTaskPeriod);
    }
}