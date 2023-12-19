#include <stdio.h>
#include <damisvm.h>

int op_jmp_equ(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_EQU\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a == b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}

int op_jmp_geq(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_GEQ\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a >= b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}

int op_jmp_leq(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_LEQ\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a <= b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}

int op_jmp_neq(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_NEQ\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a != b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}

int op_jmp_l(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_L\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a < b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}

int op_jmp_g(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t ar;
	uint8_t br;
	uint8_t jr;
	uint32_t a;
	uint32_t b;

//	INF("I: JMP_G\n");
	vm_ctx_p->pc++;
	ar = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	br = vm_ctx_p->bc[vm_ctx_p->pc];
	vm_ctx_p->pc++;
	jr = vm_ctx_p->bc[vm_ctx_p->pc];

	a = vm_ctx_p->regs[ar];
	b = vm_ctx_p->regs[br];

	if (a > b) {
		vm_ctx_p->pc = vm_ctx_p->regs[jr];
	} else {
		vm_ctx_p->pc++;
	}

	return 0;
}
