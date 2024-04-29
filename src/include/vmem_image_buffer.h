#ifndef VMEM_IMAGE_BUFFER_H
#define VMEM_IMAGE_BUFFER_H

#include <vmem/vmem.h>
#include <vmem/vmem_file.h>

#define VMEM_IMAGE_BUFFER_HEAD 0x00 // 8 bytes for head
#define VMEM_IMAGE_BUFFER_TAIL 0x04 // 8 bytes for tail
#define VMEM_IMAGE_BUFFER_LIST 0x08 // 40 bytes for list

/* Parameters for keeping track of image buffer */
#define PARAMID_IMAGE_BUFFER_LIST 100
#define PARAMID_IMAGE_BUFFER_HEAD 101
#define PARAMID_IMAGE_BUFFER_TAIL 102

/* Define file for storing image buffer */
VMEM_DEFINE_FILE(buffer, "buffer", "buffer.vmem", 1000000);

/* Define file for storing ring buffer pointers */
VMEM_DEFINE_FILE(storage, "storage", "storage.vmem", 1000);

/* Parameters for keeping track of image buffer head and tail */
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_LIST, buffer_list, PARAM_TYPE_UINT32, 10, sizeof(uint32_t), PM_CONF, NULL, NULL, storage, VMEM_IMAGE_BUFFER_LIST, "List to read image data from buffer");
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_HEAD, buffer_head, PARAM_TYPE_UINT32, -1, 0, PM_CONF, NULL, NULL, storage, VMEM_IMAGE_BUFFER_HEAD, "Write head of image data buffer");
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_TAIL, buffer_tail, PARAM_TYPE_UINT32, -1, 0, PM_CONF, NULL, NULL, storage, VMEM_IMAGE_BUFFER_TAIL, "Tail to read image data from buffer");
#endif
