#include <stdio.h>
#include <damisvm.h>

int comp_muli(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: MULI  %d = %d * %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_MULI;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;
	
	return 0;
}

int comp_mulu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: MULU  %d = %d * %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_MULU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;
	
	return 0;
}
