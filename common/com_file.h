#ifndef __COM_FILE_H
#define __COM_FILE_H

#include "com.h"

com_t *com_file_open(char *fname);
int com_file_close(void *hnd);
int com_file_read(void *hnd, uint8_t *buf, uint32_t size);
int com_file_write(void *hnd, uint8_t *buf, uint32_t size);

#endif /* __COM_FILE_H */
