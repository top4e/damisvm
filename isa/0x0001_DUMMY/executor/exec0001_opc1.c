#include <stdio.h>
#include <damisvm.h>

int exec0001_opc1(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	varL;
	uint8_t varH;
	uint16_t var;

	INF("I: 0001_OPC1\n");

	vm_ctx_p->pc++;
	varH = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	varL = vm_ctx_p->bc[vm_ctx_p->pc];

	var = (varH << 8) | varL;
	INF("I: 0001_OPC1 var=0x%04x\n", var);

	vm_ctx_p->pc++;

	return 0;
}

