#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <damisvm.h>
#include <damis_comp.h>
#include <isa/0x0001_DUMMY/compiler/comp0001.h>
#include <isa/0x0002_PERIPHERIAL/compiler/comp0002.h>
#include "com.h"

int ctx_reset(damisvm_ctx_t *vm_ctx_p)
{
	int i;

	for (i = 0; i < 32; i++) {
		vm_ctx_p->regs[i] = 0;
	}
	vm_ctx_p->pc = 0;
	vm_ctx_p->exit = 0;

	return 0;
}

int create_prog(damisvm_ctx_t *vm_ctx_p)
{
	comp_nop(vm_ctx_p);

	comp_ldli(vm_ctx_p, 0, 0xAA);
	comp_ldli(vm_ctx_p, 1, 0x55);
	comp_ldlu(vm_ctx_p, 4, 37);
	comp_ldlu(vm_ctx_p, 5, 1);
	comp_ldlu(vm_ctx_p, 6, 0);
	comp_ldlu(vm_ctx_p, 7, 100000000);

	comp_prog_start(vm_ctx_p, 1);
	comp_prog_end(vm_ctx_p);

	comp_and(vm_ctx_p, 0, 1, 2);
	comp_or(vm_ctx_p, 0, 1, 3);
	comp_not(vm_ctx_p, 0, 3);
	comp_and(vm_ctx_p, 2, 3, 3);
	comp_subu(vm_ctx_p, 7, 5, 7);
	comp_jmp_neq(vm_ctx_p, 7, 6, 4);

	comp_switch_isa(vm_ctx_p, 0x0001);
	comp0001_opc1(vm_ctx_p, 0x0001);

	comp_switch_isa(vm_ctx_p, 0x0002);
	comp0002_GPIO_Set(vm_ctx_p, 1, 1);
	comp_ldlu(vm_ctx_p, 5, 1);
	comp0002_GPIO_Get(vm_ctx_p, 1, 31);
	comp_end(vm_ctx_p);
	return 0;
}

int main(int argc, char *argv[])
{
	uint8_t		prog[256];
	damisvm_ctx_t	vm_ctx;
	com_t		*com = NULL;
	char		*fname = NULL;

	if (argc != 2) {
		INF("No output file name given\n");
		exit(1);
	}
	fname = malloc(strlen(argv[1] + 4 + 1));
	sprintf(fname, "%s.dvm", argv[1]);
	INF("Using: %s\n", fname);

	com = com_open("file", fname);
	if (com == NULL) {
		INF("Cannot open/create file %s\n", fname);
		exit(1);
	}

	ctx_reset(&vm_ctx);
	vm_ctx.bc_size = sizeof(prog);
	vm_ctx.bc = prog;

	create_prog(&vm_ctx);

	INF("Prog size = %d\n", vm_ctx.pc);
	if (com_tx(com, &vm_ctx.pc, 4) != 4) {
		INF("Cannot write to file %s\n", fname);
	}
	if (com_tx(com, vm_ctx.bc, vm_ctx.pc) != vm_ctx.pc) {
		INF("Cannot write to file %s\n", fname);
	}
	com_close(com);
	return 0;
}
