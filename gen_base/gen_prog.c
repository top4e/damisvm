#include <stdio.h>
#include <damisvm.h>

int comp_prog_start(damisvm_ctx_t *vm_ctx_p, uint16_t id)
{
	INF("C: PROG_START  id %d\n", id);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_PROG_START;
	vm_ctx_p->bc[vm_ctx_p->pc++] = id;

	
	
	return 0;
}

int comp_prog_end(damisvm_ctx_t *vm_ctx_p)
{
	INF("C: PROG_END\n");

	vm_ctx_p->ctx.prog.prog_count++;
	return 0;
}

int comp_prog_call(damisvm_ctx_t *vm_ctx_p, uint16_t id)
{
	INF("C: PROG_CALL  id %d\n", id);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_PROG_CALL;
	vm_ctx_p->bc[vm_ctx_p->pc++] = id;

	return 0;
}

int comp_prog_return(damisvm_ctx_t *vm_ctx_p)
{
	INF("C: PROG_RETURN\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_PROG_RETURN;

	return 0;
}
