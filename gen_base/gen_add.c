#include <stdio.h>
#include <damisvm.h>

int comp_addi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: ADDI  %d = %d + %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_ADDI;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp_addu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg)
{
	INF("C: ADDU  %d = %d + %d\n", res_reg, a_reg, b_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_ADDU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}
