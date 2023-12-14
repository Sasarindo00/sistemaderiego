#include "scheduler.h"

// Definición de la estructura de tarea
static Task tasks[6]; // Ajusta el tamaño del array según tus necesidades
static uint8_t numTasks = 0;
static uint32_t previousTime = 0;  // Variable para realizar un seguimiento del tiempo anterior

// Inicialización del planificador
void Scheduler_Init(void) {
    numTasks = 0;  // Inicializa el número de tareas a cero
    previousTime = HAL_GetTick();  // Inicializa el tiempo anterior al tiempo actual del sistema
}

// Agregar una tarea al planificador
void Scheduler_AddTask(void (*taskFunction)(void), uint32_t executionTime) {
    if (numTasks < sizeof(tasks) / sizeof(tasks[0])) {
        tasks[numTasks].taskFunction = taskFunction;  // Asigna la función de tarea
        tasks[numTasks].executionTime = executionTime;  // Asigna el tiempo de ejecución de la tarea
        tasks[numTasks].elapsedTime = 0;  // Inicializa el tiempo acumulado de la tarea
        numTasks++;  // Incrementa el número total de tareas
    }
}

// Ejecutar el planificador de tareas
void Scheduler_Run(void) {
    uint32_t currentTime = HAL_GetTick();  // Obtiene el tiempo actual del sistema
    uint32_t elapsedTime = currentTime - previousTime;  // Calcula el tiempo transcurrido desde la última ejecución

    // Itera a través de todas las tareas registradas
    for (uint8_t i = 0; i < numTasks; ++i) {
        tasks[i].elapsedTime += elapsedTime;  // Acumula el tiempo transcurrido para la tarea

        // Asegura que la tarea se ejecute en su momento específico
        while (tasks[i].elapsedTime >= tasks[i].executionTime) {
            tasks[i].taskFunction();  // Ejecuta la función de la tarea
            tasks[i].elapsedTime -= tasks[i].executionTime;  // Ajusta el tiempo acumulado
        }
    }

    previousTime = currentTime;  // Actualiza el tiempo anterior para el próximo ciclo
}
