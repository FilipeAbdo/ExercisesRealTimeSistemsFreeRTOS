/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"


static const char * taskOneMessage = "I am task 01";
static const char * taskTwoMessage = "I am task 02";

uint64_t idleTime = 0;

void vTaskFunction(void *pvParameters);
void sleepForTicks(TickType_t ticks);

int main(void)
{
    xTaskCreate(vTaskFunction, "Task 1", 1024, (void *)taskOneMessage, 1, NULL);
    xTaskCreate(vTaskFunction, "Task 2", 1024, (void *)taskTwoMessage, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

void vTaskFunction(void *pvParameters)
{
    char *pcTaskName;
    TickType_t xLastWakeTime;
    TickType_t xTaskPeriod = pdMS_TO_TICKS(100);//ms
    uint64_t currentIdle = 0;
    uint64_t beforeIdle = 0;
    pcTaskName = (char *) pvParameters;


    xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        if(strcmp(pcTaskName,taskOneMessage) == 0){
            printf("\033[0;31m%s ",pcTaskName);
            xTaskPeriod = pdMS_TO_TICKS(1000);//ms
            // printf("\nGoing to sleep\n");
            sleepForTicks(pdMS_TO_TICKS(200));
            printf("Time spent since start %.2f", 
                (xTaskGetTickCount() - xLastWakeTime)/((float)configTICK_RATE_HZ));
            printf("\033[0m ");    
        }else{
            printf("\033[0;32m%s\033[0m ", pcTaskName);
            xTaskPeriod = pdMS_TO_TICKS(1000);//ms
        }
        
        printf("\033[0;96m Idled for %.2f seconds\033[0m\n", 
                    currentIdle/((float)configTICK_RATE_HZ));
        
        beforeIdle = xTaskGetTickCount();
        vTaskDelayUntil(&xLastWakeTime, xTaskPeriod);
        currentIdle = (idleTime - beforeIdle);
    }
}

void vApplicationIdleHook( void ){
    idleTime = xTaskGetTickCount();
}

void sleepForTicks(TickType_t ticks){
    TickType_t atStartSleep = xTaskGetTickCount();
    while (xTaskGetTickCount() - atStartSleep < ticks);            
}