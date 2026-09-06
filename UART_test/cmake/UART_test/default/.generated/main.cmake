include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(UART_test_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(UART_test_default_default_XC8_FILE_TYPE_assemble)
add_library(UART_test_default_default_XC8_assemble OBJECT ${UART_test_default_default_XC8_FILE_TYPE_assemble})
    UART_test_default_default_XC8_assemble_rule(UART_test_default_default_XC8_assemble)
    list(APPEND UART_test_default_library_list "$<TARGET_OBJECTS:UART_test_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(UART_test_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(UART_test_default_default_XC8_assemblePreprocess OBJECT ${UART_test_default_default_XC8_FILE_TYPE_assemblePreprocess})
    UART_test_default_default_XC8_assemblePreprocess_rule(UART_test_default_default_XC8_assemblePreprocess)
    list(APPEND UART_test_default_library_list "$<TARGET_OBJECTS:UART_test_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(UART_test_default_default_XC8_FILE_TYPE_compile)
add_library(UART_test_default_default_XC8_compile OBJECT ${UART_test_default_default_XC8_FILE_TYPE_compile})
    UART_test_default_default_XC8_compile_rule(UART_test_default_default_XC8_compile)
    list(APPEND UART_test_default_library_list "$<TARGET_OBJECTS:UART_test_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(UART_test_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(UART_test_default_default_XC8_objcopy_avr OBJECT ${UART_test_default_default_XC8_FILE_TYPE_objcopy_avr})
    UART_test_default_default_XC8_objcopy_avr_rule(UART_test_default_default_XC8_objcopy_avr)
    list(APPEND UART_test_default_library_list "$<TARGET_OBJECTS:UART_test_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(UART_test_default_image_7cs0_zTE ${UART_test_default_library_list})

set_target_properties(UART_test_default_image_7cs0_zTE PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${UART_test_default_output_dir}")
target_link_libraries(UART_test_default_image_7cs0_zTE PRIVATE ${UART_test_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
UART_test_default_link_rule( UART_test_default_image_7cs0_zTE)


#Add objcopy steps
UART_test_default_objcopy_avr_rule(UART_test_default_image_7cs0_zTE)

