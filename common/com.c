#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "com.h"
#include "com_file.h"

com_t *com_open(char *type, void *attr)
{
	com_t *hnd = NULL;
	if (!strcmp("file", type)) {
		hnd =  com_file_open((char *)attr);
	}
	return hnd;
}

void com_close(com_t *hnd)
{
	if (hnd == NULL) {
		return;
	}
	hnd->close(hnd);
	free(hnd);
}

int com_rx(com_t *hnd, void *buf, uint32_t size)
{
	int rsize = 0;
	if (hnd == NULL) {
		return -1;
	}
	rsize = hnd->read(hnd->handler, buf, size);
	return rsize;
}

int com_tx(com_t *hnd, void *buf, uint32_t size)
{
	int rsize = 0;
	if (hnd == NULL) {
		return -1;
	}
	rsize = hnd->write(hnd->handler, buf, size);
	return rsize;
}
