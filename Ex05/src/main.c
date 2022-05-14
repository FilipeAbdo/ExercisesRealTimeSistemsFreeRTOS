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
    xTaskCreate(vTaskFunction, "Task 1", 1024, (void *)taskOneMessage, 1, NULL);
    xTaskCreate(vTaskFunction, "Task 2", 1024, (void *)taskTwoMessage, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

void vTaskFunction(void *pvParameters)
{
    char *pcTaskName;

    pcTaskName = (char *) pvParameters;

    for (;;)
    {
        if(strcmp(pcTaskName,taskOneMessage) == 0){
            printf("\033[0;31m%s\033[0m\r\n", pcTaskName);
        }else{
            printf("\033[0;32m%s\033[0m\r\n", pcTaskName);
        }
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}