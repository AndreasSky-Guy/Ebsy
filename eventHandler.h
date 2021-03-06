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
	uint8_t pstatus;
	uint32_t (*func)(void);
	} pcb_type;

enum processStatus {
	unused,
	running,
	ready,
	waiting,
};
//pcb_type processTable[NPROCS];

pid_t createProcess(uint32_t (*func)(void));
void handle(void);
void Sys_Init(void);
result_t destroyProcess(pid_t pid);