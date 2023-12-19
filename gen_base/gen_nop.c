#include <stdio.h>
#include <damisvm.h>

int comp_nop(damisvm_ctx_t *vm_ctx_p)
{
	INF("C: NOP\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_NOP;
	return 0;
}
