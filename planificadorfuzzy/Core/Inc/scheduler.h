#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

// Definición de la estructura de tarea
typedef struct {
    void (*taskFunction)(void);
    uint32_t executionTime;
    uint32_t elapsedTime;
} Task;

void Scheduler_Init(void);
void Scheduler_AddTask(void (*taskFunction)(void), uint32_t executionTime);
void Scheduler_Run(void);

#endif /* SCHEDULER_H */
