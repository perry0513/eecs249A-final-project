##############################################################################
# Cmake
##############################################################################

cmake_minimum_required(VERSION 3.5)
project(chirp)

# Turn -isystem off. Actually like to see warnings from underlying packages
# and regardless, have run into trouble because of the ordering it induces.
set(CMAKE_NO_SYSTEM_FROM_IMPORTED TRUE)

##############################################################################
# Find Packages
##############################################################################

find_package(ament_cmake_ros REQUIRED)

find_package(kobuki_core REQUIRED)
find_package(ecl_build REQUIRED)
find_package(ecl_command_line REQUIRED)
find_package(ecl_config REQUIRED)
find_package(ecl_console REQUIRED)
find_package(ecl_converters REQUIRED)
find_package(ecl_devices REQUIRED)
find_package(ecl_geometry REQUIRED)
find_package(ecl_threads REQUIRED)
find_package(ecl_mobile_robot REQUIRED)
find_package(ecl_sigslots REQUIRED)
find_package(ecl_time REQUIRED)
find_package(Eigen3 REQUIRED)
# include_directories(${Eigen_INCLUDE_DIRS})

##############################################################################
# Platform Configuration
##############################################################################

ament_package_xml()
ecl_enable_cxx14_compiler()
ecl_enable_cxx_warnings()

##############################################################################
# Sources
##############################################################################

# add_subdirectory(include)
# add_subdirectory(src)

##############################################################################
# Exports
##############################################################################

# ament_export_targets(${PROJECT_NAME})
# ament_export_dependencies(
#     ecl_config
#     ecl_console
#     ecl_converters
#     ecl_devices
#     ecl_geometry
#     ecl_mobile_robot
#     ecl_sigslots
#     ecl_threads
#     ecl_time
#     )

# install(
#     DIRECTORY include/
#     DESTINATION include
# )
# ament_export_include_directories(include)
# # TODO: deprecate this line post 'ardent' (been fixed upstream)
# ament_export_libraries(${PROJECT_NAME})
# ament_package()


###############################################################################
# Macro
###############################################################################

macro(kobuki_core_add_demo name)
  set(target_name kobuki_core_demo_${name})
  add_executable(${target_name} ${name}.cpp)
  target_link_libraries(${target_name}
#   ${PROJECT_NAME}
    kobuki_core::kobuki_core
    ecl_command_line::ecl_command_line
    ecl_console::ecl_console
  )
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME demo_${name})
  install(
    TARGETS
      ${target_name}
    RUNTIME DESTINATION
      lib/${PROJECT_NAME}
  )
endmacro()

###############################################################################
# Tests
###############################################################################

kobuki_core_add_demo(chirp)
# kobuki_core_add_demo(custom_logging)
# kobuki_core_add_demo(buttons)
# kobuki_core_add_demo(raw_data_stream)
# kobuki_core_add_demo(data_stream)
# kobuki_core_add_demo(velocity_commands)
# kobuki_core_add_demo(simple_loop)
