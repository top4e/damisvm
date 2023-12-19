
CC := gcc
CFLAGS := -Wall -I./ -I./op_base/ -I./gen_base/ -I./common/
CFLAGS += -O0 -ggdb
#CFLAGS += -mmcu=atmega328p -I/usr/lib/gcc/avr/4.9.2/include -Wl,-M -Wl,--cref
#CFLAGS += -Os -fomit-frame-pointer

OBJ-vm += isa/0x0001_DUMMY/executor/exec0001.o
OBJ-vm += isa/0x0001_DUMMY/executor/exec0001_opc1.o
OBJ-cl += isa/0x0001_DUMMY/compiler/comp0001_opc1.o

OBJ-vm += isa/0x0002_PERIPHERIAL/executor/exec0002.o
OBJ-vm += isa/0x0002_PERIPHERIAL/executor/exec0002_GPIO.o
OBJ-cl += isa/0x0002_PERIPHERIAL/compiler/comp0002_GPIO.o

OBJ-vm += damisvm.o
OBJ-vm += op_base/op_nop.o
OBJ-vm += op_base/op_end.o
OBJ-vm += op_base/op_add.o
OBJ-vm += op_base/op_sub.o
OBJ-vm += op_base/op_mul.o
OBJ-vm += op_base/op_div.o
OBJ-vm += op_base/op_ldl.o
OBJ-vm += op_base/op_bin.o
OBJ-vm += op_base/op_jmp.o
OBJ-vm += op_base/op_shift.o
OBJ-vm += op_base/op_prog.o
OBJ-vm += op_base/op_switch_isa.o
OBJ-vm += main_vm.o

OBJ-cl += gen_base/gen_nop.o
OBJ-cl += gen_base/gen_end.o
OBJ-cl += gen_base/gen_add.o
OBJ-cl += gen_base/gen_sub.o
OBJ-cl += gen_base/gen_mul.o
OBJ-cl += gen_base/gen_div.o
OBJ-cl += gen_base/gen_ldl.o
OBJ-cl += gen_base/gen_bin.o
OBJ-cl += gen_base/gen_jmp.o
OBJ-cl += gen_base/gen_shift.o
OBJ-cl += gen_base/gen_switch_isa.o
OBJ-cl += gen_base/gen_prog.o
OBJ-cl += common/com.o
OBJ-cl += common/com_file.o
OBJ-cl += client/client.o

#LDFLAGS := -s

all: damisvm damisclient

damisvm: $(OBJ-vm)
	$(CC) $(LDFLAGS) $(OBJ-vm) -o $@

damisclient: $(OBJ-cl)
	$(CC) $(LDFLAGS) $(OBJ-cl) -o $@

clean:
	rm -f damisclient damisvm $(OBJ-vm) $(OBJ-cl)
