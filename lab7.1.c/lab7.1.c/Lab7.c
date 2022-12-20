#include "Header.h"

int main()
{
    int task = 0;
    while (1)
    {
        task = choice(task);
        void (*taskss[3]) () = {task_1, task_2, stop};
        taskss[task - 1]();
    }
    return 0;
}