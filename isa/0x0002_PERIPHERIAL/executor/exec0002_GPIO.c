#include <stdio.h>
#include <damisvm.h>

int exec0002_GPIO_Mode(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	gpio;
	uint8_t mode;

	INF("I: 0002_GPIO_MODE\n");

	vm_ctx_p->pc++;
	gpio = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	mode = vm_ctx_p->bc[vm_ctx_p->pc];

	INF("I: 0002_GPIO_MODE gpio=%d / mode=0x%02x\n", gpio, mode);
	INF("TODO[0002]: Implement it!!!");
	vm_ctx_p->pc++;

	return 0;
}

int exec0002_GPIO_Set(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	gpio;
	uint8_t level;

	INF("I: 0002_GPIO_SET\n");

	vm_ctx_p->pc++;
	gpio = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	level = vm_ctx_p->bc[vm_ctx_p->pc];

	INF("I: 0002_GPIO_SET gpio=%d / level=%d\n", gpio, level);
	INF("TODO[0002]: Implement it!!!");
	vm_ctx_p->pc++;

	return 0;
}

int exec0002_GPIO_SetMany(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	gpio;
	uint8_t level;
	uint8_t count;
	int i;
	
	INF("I: 0002_GPIO_SET_MANY\n");

	vm_ctx_p->pc++;
	count = vm_ctx_p->bc[vm_ctx_p->pc];

	for (i = 0; i < count; i++) {
		vm_ctx_p->pc++;
		gpio = vm_ctx_p->bc[vm_ctx_p->pc];

		vm_ctx_p->pc++;
		level = vm_ctx_p->bc[vm_ctx_p->pc];

		INF("I: 0002_GPIO_SET_MANY gpio=%d / level=%d\n", gpio, level);
	}
	INF("TODO[0002]: Implement it!!!");
	vm_ctx_p->pc++;

	return 0;
}

int exec0002_GPIO_Get(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	gpio;
	uint8_t level;
	uint8_t res_reg;

	INF("I: 0002_GPIO_GET\n");

	vm_ctx_p->pc++;
	gpio = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	res_reg = vm_ctx_p->bc[vm_ctx_p->pc];

	level = 1;
	vm_ctx_p->regs[res_reg] = (uint32_t)level;
	INF("I: 0002_GPIO_GET gpio=%d / reg=%d\n", gpio, res_reg);

	INF("TODO[0002]: Implement it!!!");
	vm_ctx_p->pc++;

	return 0;
}

int exec0002_GPIO_GetMany(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t	gpio;
	uint8_t level;
	uint8_t res_reg;
	uint8_t count;
	int i;

	INF("I: 0002_GPIO_GET_MANY\n");

	vm_ctx_p->pc++;
	count = vm_ctx_p->bc[vm_ctx_p->pc];

	for (i = 0; i < count; i++) {
		vm_ctx_p->pc++;
		gpio = vm_ctx_p->bc[vm_ctx_p->pc];

		vm_ctx_p->pc++;
		res_reg = vm_ctx_p->bc[vm_ctx_p->pc];

		level = 1;
		vm_ctx_p->regs[res_reg] = (uint32_t)level;
		INF("I: 0002_GPIO_GET_MANY gpio=%d / res_reg=%d\n", gpio, res_reg);
	}
	INF("TODO[0002]: Implement it!!!");
	vm_ctx_p->pc++;
	
	return 0;
}
