#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <damisvm.h>
#include <op_base/damis_ops.h>

static const op_fn_t op_base[OP_BASE_BARIER] = {
	op_nop,		// 0x00
	op_end,

	op_addi,
	op_subi,
	op_muli,
	op_divi,

	op_addu,
	op_subu,
	op_mulu,
	op_divu,

	op_and,
	op_or,
	op_not,

	op_jmp_equ,
	op_jmp_geq,
	op_jmp_leq,
	op_jmp_neq,	//0x10
	op_jmp_l,
	op_jmp_g,

	op_shl,
	op_shr,

	op_ldli,
	op_ldlu,
	NULL,
	NULL,
	op_switch_isa,
	
	NULL,
	NULL,
	op_prog_call,
	op_prog_return,
	
};

int damisvm_reset(damisvm_ctx_t *vm_ctx_p)
{
	int i;

	for (i = 0; i < 32; i++) {
		vm_ctx_p->regs[i] = 0;
	}
	vm_ctx_p->pc = 0;
	vm_ctx_p->exit = 0;
	vm_ctx_p->isa_active = 0;

	return 0;
}

int damisvm_purge(damisvm_ctx_t *vm_ctx_p)
{
	if (vm_ctx_p->isa_array) {
		free(vm_ctx_p->isa_array);
		vm_ctx_p->isa_array = NULL;
	}

	vm_ctx_p->isa_count = 0;

	damisvm_reset(vm_ctx_p);

	return 0;
}

int damisvm_init(damisvm_ctx_t *vm_ctx_p)
{
	damisvm_reset(vm_ctx_p);
	vm_ctx_p->isa_count = 0;
	vm_ctx_p->isa_array = NULL;

	return 0;
}

int damisvm_run(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	op;
	int	res;
	op_fn_t	op_fn = NULL;

	damisvm_reset(vm_ctx_p);
	vm_ctx_p->op_base = op_base;

	while (vm_ctx_p->exit == 0) {
		op = vm_ctx_p->bc[vm_ctx_p->pc];
//		INF("Info   : PC@0x%08x / opcode=0x%02x\n", vm_ctx_p->pc, op);
		if (op < OP_BASE_BARIER) {
			op_fn = vm_ctx_p->op_base[op];
		} else {
			if (vm_ctx_p->op_active != NULL) {
				op_fn = vm_ctx_p->op_active[op - 0x20];
			} else {
				op_fn = NULL;
			}
		}

		if (op_fn == NULL) {
			INF("Error  [Invalid opcode]: PC@0x%08x / opcode=0x%02x\n", vm_ctx_p->pc, op);
			damisvm_dump_ctx(vm_ctx_p);
			return -1;
		}

		res = op_fn(vm_ctx_p);
		if (res != 0) {
			if (res > 0) {
				INF("Warning: PC@0x%08x / opcode=0x%02x\n", vm_ctx_p->pc, op);
			} else {
				INF("Error  : PC@0x%08x / opcode=0x%02x\n", vm_ctx_p->pc, op);
				damisvm_dump_ctx(vm_ctx_p);
				return -1;
			}
		}
//		damisvm_dump_ctx(vm_ctx_p);
	}

	damisvm_dump_ctx(vm_ctx_p);
	return 0;
}

int damisvm_op_register(damisvm_ctx_t *vm_ctx_p, const isa_t *isa)
{
	int res = 0;

	vm_ctx_p->isa_array = realloc(vm_ctx_p->isa_array, (vm_ctx_p->isa_count + 1) * sizeof(isa_t *));
	if (vm_ctx_p->isa_array != NULL) {
		vm_ctx_p->isa_array[vm_ctx_p->isa_count] = (isa_t *)isa;
		vm_ctx_p->isa_count++;
	} else {
		vm_ctx_p->isa_count = 0;
		return res;
	}

	return res;
}

int damisvm_dump_ctx(damisvm_ctx_t *vm_ctx_p)
{
	int i;

	INF("VM:\n");
	INF("\tPC  : 0x%08x\n", vm_ctx_p->pc);

	for (i = 0; i < 32; i++) {
		INF("\tREG%02d: 0x%08x / S=%d / U=%u\n", i, vm_ctx_p->regs[i], (int32_t)vm_ctx_p->regs[i], vm_ctx_p->regs[i]);
	}

	return 0;
}

