/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2016 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common.h"
#include "x86/intel_gt_ksanka.h"

#define PLATFORM_NAME "Intel GT Ksanka"

mraa_board_t*
mraa_gt_ksanka_board()
{
    mraa_board_t* b = (mraa_board_t*) calloc(1, sizeof(mraa_board_t));
    if (b == NULL) {
        return NULL;
    }

    b->platform_name = PLATFORM_NAME;
    b->phy_pin_count = MRAA_INTEL_GT_KSANKA_PINCOUNT;
    b->aio_count = 0;
    b->adc_raw = 0;
    b->adc_supported = 0;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t) * MRAA_INTEL_GT_KSANKA_PINCOUNT);
    if (b->pins == NULL) {
        goto error;
    }

    b->adv_func = (mraa_adv_func_t*) calloc(1, sizeof(mraa_adv_func_t));
    if (b->adv_func == NULL) {
        free(b->pins);
        goto error;
    }

    int pos = 0;
    // Ksanka header
    strncpy(b->pins[pos].name, "GND", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "GND", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "UARTCTS", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "PWRBTN", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "UARTRTS", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "RESET", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "UARTRXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "SPICLK", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "UARTTXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "SPIRXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    // pin 11

    strncpy(b->pins[pos].name, "UART1TX", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "SPIFS2", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "UART1RX", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "SPITXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2C0SCL", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2S1FS", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2C0SCL", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2S1CLK", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2C1SDA", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2S1TXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    // mislabel in datasheet SCL->SDA? Assuming SDA
    strncpy(b->pins[pos].name, "I2C1SDA", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "I2S1RXD", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 1 };
    pos++;

    strncpy(b->pins[pos].name, "GPIO0", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 337;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO1", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 338;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO2", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 339;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO3", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 340;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO4", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 341;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "IO3", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 342;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO6", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 343;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "GPIO7", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 344;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "PWM0", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 31;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "PWM1", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 32;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "PWM2", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 33;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "PWM3", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 };
    b->pins[pos].gpio.pinmap = 34;
    b->pins[pos].gpio.mux_total = 0;
    pos++;

    strncpy(b->pins[pos].name, "VDDMAIN", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "V5AIO", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "V5AIO", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "V5AIO", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "GND", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    strncpy(b->pins[pos].name, "GND", 8);
    b->pins[pos].capabilites = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 };
    pos++;

    return b;

error:
    syslog(LOG_CRIT, "GT KSANKA: Platform failed to initialise");
    free(b);
    return NULL;
}
