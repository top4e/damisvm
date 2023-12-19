#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include "com.h"

int com_file_close(void *arg)
{
	com_t *hnd = NULL;

	if (hnd == NULL) {
		return -1;
	}

	hnd = (com_t *)arg;

	if (hnd->handler) {
		int *fd;
		fd = (int *)(hnd->handler);
		close(*fd);
		free(hnd->handler);
	}
	free(hnd);

	return 0;
}

int com_file_read(void *hnd, uint8_t *buf, uint32_t size)
{
	int *fd_p = NULL;
	int fd = -1;
	int res = 0;

	if (hnd == NULL) {
		return -1;
	}
	fd_p = hnd;
	fd = *fd_p;

	res = read(fd, buf, size);

	return res;
}

int com_file_write(void *hnd, uint8_t *buf, uint32_t size)
{
	int *fd_p = NULL;
	int fd = -1;
	int res = 0;

	if (hnd == NULL) {
		return -1;
	}
	fd_p = hnd;
	fd = *fd_p;

	res = write(fd, buf, size);

	return res;
}

com_t *com_file_open(char *fname)
{
	com_t *hnd = NULL;
	int *res = NULL;
	int fd = -1;

	fd = open(fname, O_RDWR | O_CREAT, 0666);
	if (fd < 0) {
		return NULL;
	}
	res = malloc(sizeof(int));
	if (res == NULL) {
		return NULL;
	}

	*res = fd;

	hnd = malloc(sizeof(com_t));
	if (hnd == NULL) {
		close(fd);
		free(res);
		return NULL;
	}
	hnd->read = com_file_read;
	hnd->write = com_file_write;
	hnd->close = com_file_close;
	hnd->handler = (void *)res;

	printf("hnd = %p\n", hnd->handler);
	return hnd;
}
