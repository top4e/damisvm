#include <stdio.h>
#include <damisvm.h>

int comp_jmp_equ(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_EQU\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_EQU;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}

int comp_jmp_geq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_GEQ\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_GEQ;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}

int comp_jmp_leq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_LEQ\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_LEQ;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}

int comp_jmp_neq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_NEQ\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_NEQ;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}

int comp_jmp_l(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_L\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_L;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}

int comp_jmp_g(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg)
{
	INF("C: JMP_G\n");
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_BASE_JMP_G;
	vm_ctx_p->bc[vm_ctx_p->pc++] = a_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = b_reg;
	vm_ctx_p->bc[vm_ctx_p->pc++] = jmp_reg;

	return 0;
}
