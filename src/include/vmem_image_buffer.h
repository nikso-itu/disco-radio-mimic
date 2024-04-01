#ifndef VMEM_IMAGE_BUFFER_H
#define VMEM_IMAGE_BUFFER_H

#include <vmem/vmem.h>
extern vmem_t vmem_image_buffer;

#define VMEM_IMAGE_BUFFER_HEAD 0x00 // 8 bytes for head
#define VMEM_IMAGE_BUFFER_TAIL 0x08 // 8 bytes for tail
#define VMEM_IMAGE_BUFFER_DATA 0x10 // rest for image buffer

#endif
