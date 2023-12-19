#include <stdio.h>
#include <damisvm.h>

int comp_divi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: DIVI  %d = %d / %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_DIVI;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp_divu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: DIVU  %d = %d / %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_DIVU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}
