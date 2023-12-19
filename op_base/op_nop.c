#include <stdio.h>
#include <damisvm.h>

int op_nop(damisvm_ctx_t *vm_ctx_p)
{
//	INF("I: NOP\n");
	vm_ctx_p->pc++;

	return 0;
}
