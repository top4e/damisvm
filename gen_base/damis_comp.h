#ifndef __DAMIS_COMP_H
#define __DAMIS_COMP_H

int comp_nop(damisvm_ctx_t *vm_ctx_p);
int comp_end(damisvm_ctx_t *vm_ctx_p);

int comp_addi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_addu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_subi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_subu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_muli(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_mulu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_divi(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_divu(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);

int comp_and(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_or(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t res_reg);
int comp_not(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t res_reg);

int comp_shl(damisvm_ctx_t *vm_ctx_p, uint8_t reg, uint8_t bits, uint8_t dst_reg);
int comp_shr(damisvm_ctx_t *vm_ctx_p, uint8_t reg, uint8_t bits, uint8_t dst_reg);

int comp_jmp_equ(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);
int comp_jmp_geq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);
int comp_jmp_leq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);
int comp_jmp_neq(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);
int comp_jmp_l(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);
int comp_jmp_g(damisvm_ctx_t *vm_ctx_p, uint8_t a_reg, uint8_t b_reg, uint8_t jmp_reg);

int comp_ldli(damisvm_ctx_t *vm_ctx_p, uint8_t dst_reg, int32_t data);
int comp_ldlu(damisvm_ctx_t *vm_ctx_p, uint8_t dst_reg, uint32_t data);

int comp_switch_isa(damisvm_ctx_t *vm_ctx_p, uint16_t isa_code);

int comp_prog_start(damisvm_ctx_t *vm_ctx_p, uint16_t id);
int comp_prog_end(damisvm_ctx_t *vm_ctx_p);
int comp_prog_call(damisvm_ctx_t *vm_ctx_p, uint16_t id);
int comp_prog_return(damisvm_ctx_t *vm_ctx_p);

#endif /* __DAMIS_COMP_H */
