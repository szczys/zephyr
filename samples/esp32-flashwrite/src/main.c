/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(flash_test, LOG_LEVEL_DBG);

#include <zephyr/dfu/flash_img.h>
#include <zephyr/dfu/mcuboot.h>
#include <zephyr/kernel.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/sys/reboot.h>

#include "hubble_computer.h"
#define BLOCKSIZE 1024

struct flash_img_context _flash_img_context;

int main(void)
{
	LOG_INF("Started sample");
	k_msleep(2000);

	int err;

	/*boot_write_img_confirmed();*/

	err = flash_img_init(&_flash_img_context);
	if (err) {
		LOG_ERR("failed to init: %d", err);
		return err;
	} else {
		LOG_INF("Initialized flash img");
	}

	k_msleep(500);

	/* Use IMG_ERASE_PROGRESSIVELY so no explicit erase necessary */

	for (unsigned int i = 0; i < hubble_computer_len / BLOCKSIZE; i++) {
		err = flash_img_buffered_write(&_flash_img_context,
					       hubble_computer + (i * BLOCKSIZE), BLOCKSIZE, false);
		if (err) {
			LOG_ERR("Failed to write to flash: %d", err);
			return err;
		} else {
			LOG_INF("Wrote block: %u", i);
		}

		k_msleep(500);
	}

	while (true) {
		LOG_INF("Hello World! %s\n", CONFIG_BOARD_TARGET);
		k_msleep(5000);
	}

	return 0;
}
