#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <param/param.h>
#include "radio.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// TODO: Read data in ring buffer from head

void callback_setup(param_t *param, int index)
{   
    if (param_get_uint8(param) == 1)
    {
        printf("callback setup: test");

        /* Set head and tail to point to start of data */
        param_set_uint32(&buffer_head, VMEM_IMAGE_BUFFER_DATA);
        param_set_uint32(&buffer_tail, VMEM_IMAGE_BUFFER_DATA);
    } else
    {
        return;
    }   

    // Turn off setup when finished
    param_set_uint8(param, 0);
}

void callback_run(param_t *param, int index)
{
    // Turn off radio when finished
    param_set_uint8(param, 0);
}
