#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <damisvm.h>
#include <isa/0x0001_DUMMY/executor/exec0001.h>
#include <isa/0x0002_PERIPHERIAL/executor/exec0002.h>

int main(int argc, char *argv[])
{
	uint8_t		prog[256];
	damisvm_ctx_t	vm_ctx;
	int fd = -1;
	char *fname = NULL;
	
	if (argc != 2) {
		INF("No input file name given\n");
		exit(1);
	}
	fname = malloc(strlen(argv[1] + 4 + 1));
	sprintf(fname, "%s.dvm", argv[1]);
	INF("Using: %s\n", fname);
	fd = open(fname, O_RDWR | O_CREAT, 0777);
	if (fd < 0) {
		INF("Cannot open/create file %s\n", fname);
		exit(1);
	}
	if (read(fd, &vm_ctx.bc_size, 4) != 4) {
		INF("Cannot read from file %s\n", fname);
		exit(1);
		close(fd);
	}
	INF("Prog size: %d\n", vm_ctx.bc_size);
	if (read(fd, prog, vm_ctx.bc_size) != vm_ctx.bc_size) {
		INF("Cannot read from file %s\n", fname);
		exit(1);
		close(fd);
	}

	damisvm_init(&vm_ctx);
	damisvm_op_register(&vm_ctx, &isa_0001);
	damisvm_op_register(&vm_ctx, &isa_0002);
	//vm_ctx.bc_size = sizeof(prog);
	vm_ctx.bc = prog;

	damisvm_run(&vm_ctx);

	close(fd);
	return 0;
}
