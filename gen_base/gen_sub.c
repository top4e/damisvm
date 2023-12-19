#include <stdio.h>
#include <damisvm.h>

int comp_subi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: SUBI  %d = %d - %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_SUBI;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp_subu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: SUBU  %d = %d - %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_SUBU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}
