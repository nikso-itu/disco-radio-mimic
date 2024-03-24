#pragma once
#include <vmem/vmem.h>
extern vmem_t vmem_image_buffer;

#define VMEM_IMAGE_BUFFER_HEAD 0x00 // 4 bytes for head
#define VMEM_IMAGE_BUFFER_TAIL 0x04 // 4 bytes for tail
#define VMEM_IMAGE_BUFFER_DATA 0x08 // rest for image buffer
