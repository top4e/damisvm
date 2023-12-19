#include <unistd.h>
#include <damisvm.h>
#include "exec0002_int.h"

static const op_fn_t op_0002[224] = {
	exec0002_GPIO_Mode,		// 0x00
	exec0002_GPIO_Set,
	exec0002_GPIO_SetMany,
	exec0002_GPIO_Get,
	exec0002_GPIO_GetMany,
	NULL
};

const isa_t isa_0002 = {
	0x0002,
	{
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x0000001F
	},
	op_0002
};
