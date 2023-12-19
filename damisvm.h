#ifndef __DAMISVM_H
#define __DAMISVM_H

#include <stdint.h>

typedef enum damisvm_is_base_e {
	OP_BASE_NOP = 0,	/* 0xC0		No OP */
	OP_BASE_END,		/* 0xC1		End of programm */

	OP_BASE_ADDI,		/* 0xC2		+ */
	OP_BASE_SUBI,		/* 0xC3		- */
	OP_BASE_MULI,		/* 0xC4		* */
	OP_BASE_DIVI,		/* 0xC5		/ */

	OP_BASE_ADDU,		/* 0xC6		+ */
	OP_BASE_SUBU,		/* 0xC7		- */
	OP_BASE_MULU,		/* 0xC8		* */
	OP_BASE_DIVU,		/* 0xC9		/ */

	OP_BASE_AND,		/* 0xCA		& */
	OP_BASE_OR,		/* 0xCB		| */
	OP_BASE_NOT,		/* 0xCC		! */

	OP_BASE_JMP_EQU,	/* 0xCD		== */
	OP_BASE_JMP_GEQ,	/* 0xCE		>= */
	OP_BASE_JMP_LEQ,	/* 0xCF		<= */
	OP_BASE_JMP_NEQ,	/* 0xD0		!= */
	OP_BASE_JMP_L,		/* 0xD1		<  */
	OP_BASE_JMP_G,		/* 0xD2		>  */

	OP_BASE_SHL,
	OP_BASE_SHR,

	OP_BASE_LDLI,
	OP_BASE_LDLU,
	OP_BASE_STRI,
	OP_BASE_STRU,

	OP_BASE_SWITCH_ISA,

	OP_BASE_PROG_START,
	OP_BASE_PROG_END,
	OP_BASE_PROG_CALL,
	OP_BASE_PROG_RETURN,

	OP_BASE_BARIER = 32
} damisvm_is_base_t;

#define INF	printf

typedef struct damisvm_ctx_s damisvm_ctx_t;

typedef int (*op_fn_t)(damisvm_ctx_t *vm_ctx_p);

typedef struct isa_s {
	uint16_t		isa_code;
	uint32_t		opc_mask[7];
	op_fn_t const		*isa;
} isa_t;

typedef struct damisvm_prog_ctx_s {
	uint16_t	prog_count;
	uint16_t	*prog_id;
	uint16_t	*prog_offset;
	uint16_t	bcode_size;
	uint8_t		*bc;
} damisvm_prog_ctx_t;

typedef struct damisvm_sub_ctx_s {
	damisvm_prog_ctx_t	prog;
} damisvm_sub_ctx_t;

struct damisvm_ctx_s {
	uint32_t		bc_size;
	uint8_t			*bc;
	uint32_t		pc;
	int8_t			exit;
	uint32_t		regs[32];
	op_fn_t const		*op_base;
	op_fn_t const		*op_active;
	uint16_t		isa_active;
	uint16_t		isa_count;
	isa_t			**isa_array;
	damisvm_sub_ctx_t	ctx;
};

int damisvm_op_register(damisvm_ctx_t *vm_ctx_p, const isa_t *isa);
int damisvm_dump_ctx(damisvm_ctx_t *vm_ctx_p);
int damisvm_run(damisvm_ctx_t *vm_ctx_p);
int damisvm_init(damisvm_ctx_t *vm_ctx_p);
int damisvm_reset(damisvm_ctx_t *vm_ctx_p);
int damisvm_purge(damisvm_ctx_t *vm_ctx_p);

#endif /* __DAMISVM_H */
