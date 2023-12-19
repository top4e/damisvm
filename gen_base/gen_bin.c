#include <stdio.h>
#include <damisvm.h>

int comp_and(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: AND\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_AND;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp_or(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: OR\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_OR;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp_not(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t res_reg)
{
	INF("C: NOT\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_NOT;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}
