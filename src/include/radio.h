#ifndef RADIO_H
#define RADIO_H

#include <param/param.h>
#include "radio_params.h"
#include "vmem_image_buffer.h"

/* Parameters for keeping track of image buffer head and tail */
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_HEAD, buffer_head, PARAM_TYPE_UINT32, -1, 0, PM_CONF, NULL, NULL, image_buffer, VMEM_IMAGE_BUFFER_HEAD, NULL);
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_TAIL, buffer_tail, PARAM_TYPE_UINT32, -1, 0, PM_CONF, NULL, NULL, image_buffer, VMEM_IMAGE_BUFFER_TAIL, NULL);

// TODO: Figure out how to define ring buffer in vmem (like we do with parameters)

/* Parameter for running the radio */
static uint8_t _radio_run = 0;
void callback_run(param_t *param, int index);
PARAM_DEFINE_STATIC_RAM(PARAMID_RADIO_RUN, radio_run, PARAM_TYPE_UINT8, -1, 0, PM_CONF, callback_run, NULL, &_radio_run, "Set the radio to execute");

#endif