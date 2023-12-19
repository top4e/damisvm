#include <stdio.h>
#include <damisvm.h>

int comp_end(damisvm_ctx_t *vm_ctx_p)
{
	INF("C: END\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_END;
	return 0;
}
