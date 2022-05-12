/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

#define DELAY_LOOP_COUNT 500000

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{
    xTaskCreate(&vTask1, "Task 1", 1024, NULL, 1, NULL);
    xTaskCreate(&vTask2, "Task 2", 1024, NULL, 2, NULL);

    vTaskStartScheduler();

    return 0;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        printf("\033[0;32mTask 1\033[0m\r\n");
        for(int ul = 0; ul < DELAY_LOOP_COUNT; ul++ ){}
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        printf("\033[0;31mTask 2\033[0m\r\n");
        for(int ul = 0; ul < DELAY_LOOP_COUNT; ul++ ){}
    
    }
}
