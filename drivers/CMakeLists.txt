#
# Copyright (c) 2018-2020 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

add_subdirectory(entropy)
add_subdirectory(serial)

add_subdirectory_ifdef(CONFIG_MPSL mpsl)
add_subdirectory_ifdef(CONFIG_WIFI wifi)
