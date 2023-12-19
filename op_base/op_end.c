#include <stdio.h>
#include <damisvm.h>

int op_end(damisvm_ctx_t *vm_ctx_p)
{
	//INF("I: END\n");
	vm_ctx_p->pc++;
	vm_ctx_p->exit = 1;
	return 0;
}
