#include <stdio.h>
#include <damisvm.h>

int op_switch_isa(damisvm_ctx_t *vm_ctx_p)
{
	uint8_t isa_codeL;
	uint8_t isa_codeH;
	uint16_t isa_code;
	int i;
	int isa_idx = -1;
	int res = 0;

	INF("I: SWITCH_ISA\n");

	vm_ctx_p->pc++;
	isa_codeH = vm_ctx_p->bc[vm_ctx_p->pc];

	vm_ctx_p->pc++;
	isa_codeL = vm_ctx_p->bc[vm_ctx_p->pc];

	isa_code = (isa_codeH << 8) | isa_codeL;
	for (i = 0; i < vm_ctx_p->isa_count; i++) {

		if (vm_ctx_p->isa_array[i]->isa_code == isa_code) {
			isa_idx = i;
			break;
		}
	}
	
	if (isa_idx == -1) {
		INF("E: SWITCH_ISA:  ISA code 0x%04x not supported on this VM\n", isa_code);
		res = -1;
	} else {
		INF("I: SWITCH_ISA ISA 0x%04x -> ISA 0x%04x\n", vm_ctx_p->isa_active, isa_code);
		vm_ctx_p->isa_active = isa_code;
		vm_ctx_p->op_active = vm_ctx_p->isa_array[i]->isa;
	}

	vm_ctx_p->pc++;

	return res;
}
