/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

#define DELAY_COUNTER 200000000

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{
    xTaskCreate(&vTask1, "Task 1", 1024, NULL, 1, NULL);
    xTaskCreate(&vTask2, "Task 2", 1024, NULL, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        printf("\033[0;32mTask 1\033[0m\r\n");
        for(int i=0; i<10; i++){
            printf("\033[0;32mCounting Green %d\033[0m\n", i);
            for(int ul=0; ul<DELAY_COUNTER;ul++){}
        }
        vTaskDelay(pdMS_TO_TICKS(150));
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        printf("\033[0;31mTask 2\033[0m\r\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
