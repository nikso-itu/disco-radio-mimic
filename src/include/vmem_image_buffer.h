#ifndef VMEM_IMAGE_BUFFER_H
#define VMEM_IMAGE_BUFFER_H

#include <vmem/vmem.h>
#include <vmem/vmem_ring.h>

VMEM_DEFINE_RING(images, "images", "images.vmem", 10000000, 20);

#endif
