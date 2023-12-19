#include <stdio.h>
#include <damisvm.h>

int comp_ldli(damisvm_ctx_t *vm_ctx_p, uint8_t dst_reg, int32_t data)
{
	INF("C: LDLI -> %d | 0x%08x\n", dst_reg, data);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_LDLI;
	vm_ctx_p->bc[vm_ctx_p->pc++] = dst_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = ((uint32_t)data >> 24) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = ((uint32_t)data >> 16) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = ((uint32_t)data >>  8) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = ((uint32_t)data >>  0) & 0xFF;
	return 0;
}

int comp_ldlu(damisvm_ctx_t *vm_ctx_p, uint8_t dst_reg, uint32_t data)
{
	INF("C: LDLU -> %d | 0x%08x\n", dst_reg, data);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_LDLU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = dst_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (data >> 24) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (data >> 16) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (data >>  8) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (data >>  0) & 0xFF;
	return 0;
}
