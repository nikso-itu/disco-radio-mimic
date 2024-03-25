#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <param/param.h>
#include <vmem/vmem_file.h>
#include "radio.h"
#include "vmem_image_buffer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int image_count = 0;

char* read_image_data()
{
    /* Fetch tail pointer */
    uint32_t tail = param_get_uint32(&buffer_tail);
    uint32_t head = param_get_uint32(&buffer_head);

    /* Guard against empty buffer */
    if (tail == head) {
        printf("No data in image buffer.\n");
        return NULL;
    }

    /* Find size of next image in buffer */
    size_t image_size_buf;
    vmem_file_read(&vmem_image_buffer, tail, image_size_buf, sizeof(size_t));

    /* Fetch image data from buffer */
    char * image_data[image_size_buf];
    vmem_file_read(&vmem_image_buffer, tail + sizeof(size_t), image_data, image_size_buf);
    
    /* Set tail to point to next image */
    param_set_uint32(&buffer_tail, tail + sizeof(size_t) + image_size_buf);

    printf("Read data of size %d from image buffer.\n", image_size_buf);
    return image_data;
}


void save_image(const char *filename_base, const char * image_data)
{
    char filename[20];
    sprintf(filename, "%s%d.png", filename_base, image_count++);
    
    /* Hardcoded values for sim_image.png */
    int channels = 4;
    int width = 950;
    int height = 1373;

    int stride = width * channels * sizeof(uint8_t);

    int success = stbi_write_png(filename, width, height, channels, image_data, stride);
    if (!success)
    {
        fprintf(stderr, "Error writing image to %s\n", filename);
    }
    else
    {
        printf("Image saved as %s\n", filename);
    }
}

void callback_setup(param_t *param, int index)
{   
    if (param_get_uint8(param) == 1)
    {
        printf("callback setup: test\n");

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
    char* image = read_image_data();
    save_image("image", image);

    // Turn off radio when finished
    param_set_uint8(param, 0);
}
