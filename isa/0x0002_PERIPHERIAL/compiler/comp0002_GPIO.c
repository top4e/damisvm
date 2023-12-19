#include <stdio.h>
#include <damisvm.h>
#include "comp0002.h"

int comp0002_GPIO_Mode(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t mode)
{
	INF("C: 0002_GPIO_MODE  gpio=%d / mode=0x%02x\n", gpio, mode);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0002_GPIO_MODE;
	vm_ctx_p->bc[vm_ctx_p->pc++] = gpio;
	vm_ctx_p->bc[vm_ctx_p->pc++] = mode;

	return 0;
}

int comp0002_GPIO_Set(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t level)
{
	INF("C: 0002_GPIO_SET  gpio=%d / level=%d\n", gpio, level);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0002_GPIO_SET;
	vm_ctx_p->bc[vm_ctx_p->pc++] = gpio;
	vm_ctx_p->bc[vm_ctx_p->pc++] = level;

	return 0;
}
int comp0002_GPIO_SetMany(damisvm_ctx_t *vm_ctx_p, uint8_t count, uint8_t *gpios_p, uint8_t *levels_p)
{
	int i;
	INF("C: 0002_GPIO_SET_MANY count=%d\n", count);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0002_GPIO_SET_MANY;
	vm_ctx_p->bc[vm_ctx_p->pc++] = count;
	for (i = 0; i < count; i++) {
		vm_ctx_p->bc[vm_ctx_p->pc++] = gpios_p[i];
		vm_ctx_p->bc[vm_ctx_p->pc++] = levels_p[i];
	}

	return 0;
}

int comp0002_GPIO_Get(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t res_reg)
{
	INF("C: 0002_GPIO_GET  gpio=%d / res_reg=%d\n", gpio, res_reg);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0002_GPIO_GET;
	vm_ctx_p->bc[vm_ctx_p->pc++] = gpio;
	vm_ctx_p->bc[vm_ctx_p->pc++] = res_reg;

	return 0;
}

int comp0002_GPIO_GetMany(damisvm_ctx_t *vm_ctx_p, uint8_t count, uint8_t *gpios_p, uint8_t *res_regs_p)
{
	int i;
	INF("C: 0002_GPIO_GET_MANY  count=%d\n", count);
	vm_ctx_p->bc[vm_ctx_p->pc++] = OP_0002_GPIO_GET_MANY;
	vm_ctx_p->bc[vm_ctx_p->pc++] = count;
	for (i = 0; i < count; i++) {
		vm_ctx_p->bc[vm_ctx_p->pc++] = gpios_p[i];
		vm_ctx_p->bc[vm_ctx_p->pc++] = res_regs_p[i];
	}
	return 0;
}
