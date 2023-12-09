
add_subdirectory_ifdef(CONFIG_BT_LL_SOFTDEVICE controller)

if(CONFIG_BT)
  zephyr_link_libraries(INTERFACE SOFTDEVICE_CONTROLLER_LIB_HEADERS)
endif()
