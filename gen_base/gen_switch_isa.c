#include <stdio.h>
#include <damisvm.h>

int comp_switch_isa(damisvm_ctx_t *vm_ctx_p, uint16_t isa_code)
{
	INF("C: SWITCH_ISA  ISA_CODE=0x%04x\n", isa_code);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_SWITCH_ISA;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (isa_code >> 8) & 0xFF;
	vm_ctx_p->bc[vm_ctx_p->pc++] = (isa_code >> 0) & 0xFF;

	return 0;
}
