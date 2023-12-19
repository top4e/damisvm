#include <stdio.h>
#include <damisvm.h>
#include "comp0001.h"

int comp0001_opc1(damisvm_ctx_t *vm_ctx_p, uint16_t var1)
{
	INF("C: 0001_OPC1  var1=%d\n", var1);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0001_OPC1;
	vm_ctx_p->bc[vm_ctx_p->pc++] = var1 >> 8;
	vm_ctx_p->bc[vm_ctx_p->pc++] = var1;

	return 0;
}

