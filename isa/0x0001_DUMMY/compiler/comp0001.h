#ifndef __COMP_0001_H
#define __COMP_0001_H

typedef enum damisvm_is_0001_dummy_e {
	OP_0001_OPC1 = 32,
} damisvm_is_0001_dummy_t;

int comp0001_opc1(damisvm_ctx_t *vm_ctx_p, uint16_t var1);

#endif /* __COMP_0001_H */

