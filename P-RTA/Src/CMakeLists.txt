cmake_minimum_required (VERSION 3.1)

#set(CMAKE_SYSTEM_NAME               Generic)
#set(CMAKE_SYSTEM_PROCESSOR          arm)

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE   STATIC_LIBRARY)

set(CMAKE_AR                        /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-ar)
set(CMAKE_ASM_COMPILER              /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-gcc)
set(CMAKE_C_COMPILER                /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER              /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-g++)
set(CMAKE_LINKER                    /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-ld)
set(CMAKE_OBJCOPY                   /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-objcopy CACHE INTERNAL "")
set(CMAKE_RANLIB                    /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-ranlib CACHE INTERNAL "")
set(CMAKE_SIZE                      /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-size CACHE INTERNAL "")
set(CMAKE_STRIP                     /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-strip CACHE INTERNAL "")
set(CMAKE_GCOV                      /usr/local/Cellar/arm-none-eabi-gcc/10.3-2021.07/bin/arm-none-eabi-gcov CACHE INTERNAL "")

set(CMAKE_C_FLAGS                   "${APP_C_FLAGS} -Wno-psabi --specs=nosys.specs -fdata-sections -ffunction-sections -Wl,--gc-sections" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS                 "${APP_CXX_FLAGS} ${CMAKE_C_FLAGS} -fno-exceptions" CACHE INTERNAL "")

set(CMAKE_C_FLAGS_DEBUG             "-Os -g" CACHE INTERNAL "")
set(CMAKE_C_FLAGS_RELEASE           "-Os -DNDEBUG" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_DEBUG           "${CMAKE_C_FLAGS_DEBUG}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS_RELEASE         "${CMAKE_C_FLAGS_RELEASE}" CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

project (P)

add_definitions( -DPRT_PLAT_LINUXUSER )

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(LINUX ON)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(MACOSX ON)
endif()

if (NOT Win32)
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	  add_definitions( -DPRT_USE_CLANG)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	  add_definitions( -DPRT_USE_GCC )
	endif()
endif()

if(SGX)
    add_definitions( -DPRT_PLAT_SGXUSER )
elseif(Win32)
    add_definitions( -DPRT_PLAT_WINUSER )
elseif(LINUX OR MACOSX)
    add_definitions( -DPRT_PLAT_LINUXUSER )
endif()

macro ( Publish_Library_Header target )
	set (extra_macro_args ${ARGN})
	list(LENGTH extra_macro_args num_extra_args)
	if(${num_extra_args} EQUAL 0)
		get_property(Published_Headers_PATHS TARGET ${target} PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
	else()
		set(Published_Headers_PATHS "${ARGN}")
	endif()
	add_custom_command(TARGET ${target} POST_BUILD
	  COMMENT "Moving header files to Bld/include/"
	  COMMAND ${CMAKE_COMMAND} ARGS -E
	    make_directory ${LIBRARY_OUTPUT_INCLUDE_PATH}
	)

	foreach(incl_file_path ${Published_Headers_PATHS})
		file ( GLOB incl_files ${incl_file_path}/*.h )
		foreach(incl_file ${incl_files})
			add_custom_command(TARGET ${target} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different 
					${incl_file}
			       	${LIBRARY_OUTPUT_INCLUDE_PATH}
			)
		endforeach()
	endforeach()
endmacro()

add_subdirectory ( PRuntimes/CRuntime )

