#ifndef RADIO_H
#define RADIO_H

#include <param/param.h>
#include "radio_params.h"
#include "vmem_image_buffer.h"

/* Parameters for keeping track of image buffer head and tail */
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_HEAD, buffer_head, PARAM_TYPE_UINT64, -1, 0, PM_CONF, NULL, NULL, image_buffer, VMEM_IMAGE_BUFFER_HEAD, "Write head of image data buffer");
PARAM_DEFINE_STATIC_VMEM(PARAMID_IMAGE_BUFFER_TAIL, buffer_tail, PARAM_TYPE_UINT64, -1, 0, PM_CONF, NULL, NULL, image_buffer, VMEM_IMAGE_BUFFER_TAIL, "Tail to read image data from buffer");

/* Parameter for setting up radio params */
static uint8_t _radio_setup = 0;
void callback_setup(param_t *param, int index);
PARAM_DEFINE_STATIC_RAM(PARAMID_RADIO_SETUP, radio_setup, PARAM_TYPE_UINT8, -1, 0, PM_CONF, callback_setup, NULL, &_radio_setup, "Set up the radio");


/* Parameter for running the radio */
static uint8_t _radio_run = 0;
void callback_run(param_t *param, int index);
PARAM_DEFINE_STATIC_RAM(PARAMID_RADIO_RUN, radio_run, PARAM_TYPE_UINT8, -1, 0, PM_CONF, callback_run, NULL, &_radio_run, "Set the radio to execute");

#endif