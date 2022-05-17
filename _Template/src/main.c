/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

//Put your tasks prototypes or implementations here

int main(void)
{
    // Create Tasks here

    vTaskStartScheduler();

    return 0;
}

