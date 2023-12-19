#ifndef __COM_H
#define __COM_H

typedef int (*io_fn_t)(void *hnd, uint8_t *buf, uint32_t size);
typedef int (*close_fn_t)(void *hnd);

typedef struct com_s {
	void		*handler;
	io_fn_t		read;
	io_fn_t		write;
	close_fn_t	close;
} com_t;

com_t *com_open(char *type, void *attr);
void com_close(com_t *hnd);

int com_rx(com_t *hnd, void *buf, uint32_t size);
int com_tx(com_t *hnd, void *buf, uint32_t size);

#endif /* __COM_H */
