#include <stdio.h>
#include <damisvm.h>

int op_and(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t rr;
	uint32_t a;
	uint32_t b;
	uint32_t res;

//	INF("I: AND\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	rr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	res = a & b;

	vm_ctx_p->regs[rr] = res;

	vm_ctx_p->pc++;

	return 0;
}

int op_or(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t rr;
	uint32_t a;
	uint32_t b;
	uint32_t res;

//	INF("I: OR\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	rr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	res = a | b;

	vm_ctx_p->regs[rr] = res;

	vm_ctx_p->pc++;

	return 0;
}

int op_not(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t rr;
	uint32_t a;
	uint32_t res;

//	INF("I: NOT\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	rr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];

	res = ~a;

	vm_ctx_p->regs[rr] = res;

	vm_ctx_p->pc++;

	return 0;
}
