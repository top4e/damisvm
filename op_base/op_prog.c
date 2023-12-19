#include <stdio.h>
#include <damisvm.h>

int op_prog_call(damisvm_ctx_t *vm_ctx_p)
{
	INF("I: PROG_CALL\n");
	vm_ctx_p->pc++;

	return 0;
}

int op_prog_return(damisvm_ctx_t *vm_ctx_p)
{
	INF("I: PROG_RETURN\n");
	vm_ctx_p->pc++;

	return 0;
}
