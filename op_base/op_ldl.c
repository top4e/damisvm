#include <stdio.h>
#include <damisvm.h>

int op_ldli(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t		dst_reg;
	uint32_t	data = 0;

//	INF("I: LDLI\n");
	vm_ctx_p->pc++;
	dst_reg = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	data = vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->regs[dst_reg] = data;

	vm_ctx_p->pc++;
	return 0;
}

int op_ldlu(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t		dst_reg;
	uint32_t	data = 0;

//	INF("I: LDLU\n");
	vm_ctx_p->pc++;
	dst_reg = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	data = vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	data = data << 8;
	vm_ctx_p->pc++;
	data |= vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->regs[dst_reg] = data;

	vm_ctx_p->pc++;
	return 0;
}
