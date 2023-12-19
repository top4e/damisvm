#include <unistd.h>
#include <damisvm.h>
#include "exec0001_int.h"

static const op_fn_t op_0001[224] = {
	exec0001_opc1,		// 0x00
	NULL
};

const isa_t isa_0001 = {
	0x0001,
	{
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000001
	},
	op_0001
};
