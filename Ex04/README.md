# Exercise 04

### Creating 2 tasks one does nothing and the other does loop delay, both call *"vTaskDelay(pdMS_TO_TICKS(ms));"*

1. Lets play with priorities, since the delays are no multiples deu to the loop delay, task one will overlap task 2. Changing priority will dramatically changes the scheduler outputs.