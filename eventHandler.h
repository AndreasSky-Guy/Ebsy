#include <stdint.h>

#define INTERVAL_10ms 10
#define INTERVAL_50ms 50
#define INTERVAL_100ms 100
#define NPROCS 4

typedef struct {
	uint16_t Interval;
	uint32_t LastTick;
	void (*Func)(void);
} TaskType;

typedef uint32_t result_t;
typedef uint32_t pid_t;

typedef struct {
	pid_t id;
	uint32_t (*func)(uint8_t a) ;
} pcb_type;

pcb_type processTable[NPROCS];

pid_t createProcess(int id, uint32_t (*func)(uint8_t a));
	
void handle(void);
void Sys_Init(void);
