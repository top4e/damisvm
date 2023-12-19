#ifndef __COMP_0002_H
#define __COMP_0002_H

typedef enum damisvm_is_0002_peripherial_e {
	OP_0002_GPIO_MODE = 32,
	OP_0002_GPIO_SET,
	OP_0002_GPIO_SET_MANY,
	OP_0002_GPIO_GET,
	OP_0002_GPIO_GET_MANY,
} damisvm_is_0002_peripherial_t;

int comp0002_GPIO_Mode(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t mode);
int comp0002_GPIO_Set(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t level);
int comp0002_GPIO_SetMany(damisvm_ctx_t *vm_ctx_p, uint8_t count, uint8_t *gpios_p, uint8_t *levels_p);
int comp0002_GPIO_Get(damisvm_ctx_t *vm_ctx_p, uint8_t gpio, uint8_t res_reg);
int comp0002_GPIO_GetMany(damisvm_ctx_t *vm_ctx_p, uint8_t count, uint8_t *gpios_p, uint8_t *res_regs_p);

#endif /* __COMP_0001_H */

