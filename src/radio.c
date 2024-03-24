#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <param/param.h>
#include "radio.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// TODO: Define image ring buffer in radio.h
// TODO: Read data in ring buffer from head

void callback_run(param_t *param, int index)
{
    // Turn off radio when finished
    param_set_uint8(param, 0);
}
