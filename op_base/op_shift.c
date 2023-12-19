#include <stdio.h>
#include <damisvm.h>

int op_shl(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t reg;
	uint8_t bits;
	uint8_t reg_dst;

//	INF("I: SHL\n");

	reg      = vm_ctx_p->bc[vm_ctx_p->pc++];
	bits     = vm_ctx_p->bc[vm_ctx_p->pc++];
	reg_dst  = vm_ctx_p->bc[vm_ctx_p->pc++];

	vm_ctx_p->regs[reg_dst] = vm_ctx_p->regs[reg] << bits;

	vm_ctx_p->pc++;

	return 0;
}

int op_shr(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t reg;
	uint8_t bits;
	uint8_t reg_dst;

//	INF("I: SHR\n");

	reg      = vm_ctx_p->bc[vm_ctx_p->pc++];
	bits     = vm_ctx_p->bc[vm_ctx_p->pc++];
	reg_dst  = vm_ctx_p->bc[vm_ctx_p->pc++];

	vm_ctx_p->regs[reg_dst] = vm_ctx_p->regs[reg] >> bits;

	vm_ctx_p->pc++;

	return 0;
}
