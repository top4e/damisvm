#include <stdio.h>
#include <damisvm.h>

int comp_shl(damisvm_ctx_t *vm_ctx_p, uint8_t reg, uint8_t bits, uint8_t dst_reg)
{
	INF("C: SHL  REG%d = REG%d << %d\n", dst_reg, reg, bits);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_SHL;
	vm_ctx_p->bc[vm_ctx_p->pc++] = reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = bits;
	vm_ctx_p->bc[vm_ctx_p->pc++] = dst_reg;

	return 0;
}

int comp_shr(damisvm_ctx_t *vm_ctx_p, uint8_t reg, uint8_t bits, uint8_t dst_reg)
{
	INF("C: SHR  REG%d = REG%d >> %d\n", dst_reg, reg, bits);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_SHR;
	vm_ctx_p->bc[vm_ctx_p->pc++] = reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = bits;
	vm_ctx_p->bc[vm_ctx_p->pc++] = dst_reg;

	return 0;
}
