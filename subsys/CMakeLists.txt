
add_subdirectory_ifdef(CONFIG_BT bluetooth)

if (CONFIG_MPSL AND NOT CONFIG_MPSL_FEM_ONLY)
  add_subdirectory(mpsl/init)
endif()

if (CONFIG_MPSL_FEM OR CONFIG_MPSL_FEM_PIN_FORWARDER OR CONFIG_MPSL_FEM_API_AVAILABLE)
  add_subdirectory(mpsl/fem)
endif()
