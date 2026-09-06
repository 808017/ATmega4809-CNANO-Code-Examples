include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(OLED_Temp_Monitor_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_assemble)
add_library(OLED_Temp_Monitor_default_default_XC8_assemble OBJECT ${OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_assemble})
    OLED_Temp_Monitor_default_default_XC8_assemble_rule(OLED_Temp_Monitor_default_default_XC8_assemble)
    list(APPEND OLED_Temp_Monitor_default_library_list "$<TARGET_OBJECTS:OLED_Temp_Monitor_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(OLED_Temp_Monitor_default_default_XC8_assemblePreprocess OBJECT ${OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_assemblePreprocess})
    OLED_Temp_Monitor_default_default_XC8_assemblePreprocess_rule(OLED_Temp_Monitor_default_default_XC8_assemblePreprocess)
    list(APPEND OLED_Temp_Monitor_default_library_list "$<TARGET_OBJECTS:OLED_Temp_Monitor_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_compile)
add_library(OLED_Temp_Monitor_default_default_XC8_compile OBJECT ${OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_compile})
    OLED_Temp_Monitor_default_default_XC8_compile_rule(OLED_Temp_Monitor_default_default_XC8_compile)
    list(APPEND OLED_Temp_Monitor_default_library_list "$<TARGET_OBJECTS:OLED_Temp_Monitor_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(OLED_Temp_Monitor_default_default_XC8_objcopy_avr OBJECT ${OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_objcopy_avr})
    OLED_Temp_Monitor_default_default_XC8_objcopy_avr_rule(OLED_Temp_Monitor_default_default_XC8_objcopy_avr)
    list(APPEND OLED_Temp_Monitor_default_library_list "$<TARGET_OBJECTS:OLED_Temp_Monitor_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(OLED_Temp_Monitor_default_image_F67Q6DiN ${OLED_Temp_Monitor_default_library_list})

set_target_properties(OLED_Temp_Monitor_default_image_F67Q6DiN PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${OLED_Temp_Monitor_default_output_dir}")
target_link_libraries(OLED_Temp_Monitor_default_image_F67Q6DiN PRIVATE ${OLED_Temp_Monitor_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
OLED_Temp_Monitor_default_link_rule( OLED_Temp_Monitor_default_image_F67Q6DiN)


#Add objcopy steps
OLED_Temp_Monitor_default_objcopy_avr_rule(OLED_Temp_Monitor_default_image_F67Q6DiN)

