#include <stdio.h>
#include <damisvm.h>

int op_subi(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t rr;
	int32_t a;
	int32_t b;
	int32_t res;

//	INF("I: SUBI\n");

	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	rr = vm_ctx_p->bc[vm_ctx_p->pc];
//	INF("I: SUBI  %d = %d - %d\n", rr, ar, br);

	a = (int32_t) vm_ctx_p->regs[ar];
	b = (int32_t) vm_ctx_p->regs[br];
	res = a - b;
	vm_ctx_p->regs[rr] = (uint32_t)res;

	vm_ctx_p->pc++;

	return 0;
}

int op_subu(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t rr;
	uint32_t a;
	uint32_t b;
	uint32_t res;

	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	rr = vm_ctx_p->bc[vm_ctx_p->pc];

//	INF("I: SUBU  %d = %d - %d\n", ar, br, rr);

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];
	res = a - b;
	vm_ctx_p->regs[rr] = res;

	vm_ctx_p->pc++;

	return 0;
}
