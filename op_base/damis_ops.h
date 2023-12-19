#ifndef __DAMIS_OPS_H
#define __DAMIS_OPS_H

int op_nop(damisvm_ctx_t *vm_ctx_p);
int op_end(damisvm_ctx_t *vm_ctx_p);
int op_addi(damisvm_ctx_t *vm_ctx_p);
int op_addu(damisvm_ctx_t *vm_ctx_p);
int op_subi(damisvm_ctx_t *vm_ctx_p);
int op_subu(damisvm_ctx_t *vm_ctx_p);
int op_muli(damisvm_ctx_t *vm_ctx_p);
int op_mulu(damisvm_ctx_t *vm_ctx_p);
int op_divi(damisvm_ctx_t *vm_ctx_p);
int op_divu(damisvm_ctx_t *vm_ctx_p);

int op_and(damisvm_ctx_t *vm_ctx_p);
int op_or(damisvm_ctx_t *vm_ctx_p);
int op_not(damisvm_ctx_t *vm_ctx_p);

int op_shl(damisvm_ctx_t *vm_ctx_p);
int op_shr(damisvm_ctx_t *vm_ctx_p);

int op_jmp_equ(damisvm_ctx_t *vm_ctx_p);
int op_jmp_geq(damisvm_ctx_t *vm_ctx_p);
int op_jmp_leq(damisvm_ctx_t *vm_ctx_p);
int op_jmp_neq(damisvm_ctx_t *vm_ctx_p);
int op_jmp_l(damisvm_ctx_t *vm_ctx_p);
int op_jmp_g(damisvm_ctx_t *vm_ctx_p);

int op_ldli(damisvm_ctx_t *vm_ctx_p);
int op_ldlu(damisvm_ctx_t *vm_ctx_p);

int op_prog_call(damisvm_ctx_t *vm_ctx_p);
int op_prog_return(damisvm_ctx_t *vm_ctx_p);

int op_switch_isa(damisvm_ctx_t *vm_ctx_p);

#endif /* __DAMIS_OPS_H */
