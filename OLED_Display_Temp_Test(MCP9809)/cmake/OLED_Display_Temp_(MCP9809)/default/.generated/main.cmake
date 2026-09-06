include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(OLED_Display_Temp__MCP9809__default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_assemble)
add_library(OLED_Display_Temp__MCP9809__default_default_XC8_assemble OBJECT ${OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_assemble})
    OLED_Display_Temp__MCP9809__default_default_XC8_assemble_rule(OLED_Display_Temp__MCP9809__default_default_XC8_assemble)
    list(APPEND OLED_Display_Temp__MCP9809__default_library_list "$<TARGET_OBJECTS:OLED_Display_Temp__MCP9809__default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(OLED_Display_Temp__MCP9809__default_default_XC8_assemblePreprocess OBJECT ${OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_assemblePreprocess})
    OLED_Display_Temp__MCP9809__default_default_XC8_assemblePreprocess_rule(OLED_Display_Temp__MCP9809__default_default_XC8_assemblePreprocess)
    list(APPEND OLED_Display_Temp__MCP9809__default_library_list "$<TARGET_OBJECTS:OLED_Display_Temp__MCP9809__default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_compile)
add_library(OLED_Display_Temp__MCP9809__default_default_XC8_compile OBJECT ${OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_compile})
    OLED_Display_Temp__MCP9809__default_default_XC8_compile_rule(OLED_Display_Temp__MCP9809__default_default_XC8_compile)
    list(APPEND OLED_Display_Temp__MCP9809__default_library_list "$<TARGET_OBJECTS:OLED_Display_Temp__MCP9809__default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(OLED_Display_Temp__MCP9809__default_default_XC8_objcopy_avr OBJECT ${OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_objcopy_avr})
    OLED_Display_Temp__MCP9809__default_default_XC8_objcopy_avr_rule(OLED_Display_Temp__MCP9809__default_default_XC8_objcopy_avr)
    list(APPEND OLED_Display_Temp__MCP9809__default_library_list "$<TARGET_OBJECTS:OLED_Display_Temp__MCP9809__default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(OLED_Display_Temp__MCP9809__default_image__DDS6wMG ${OLED_Display_Temp__MCP9809__default_library_list})

set_target_properties(OLED_Display_Temp__MCP9809__default_image__DDS6wMG PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${OLED_Display_Temp__MCP9809__default_output_dir}")
target_link_libraries(OLED_Display_Temp__MCP9809__default_image__DDS6wMG PRIVATE ${OLED_Display_Temp__MCP9809__default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
OLED_Display_Temp__MCP9809__default_link_rule( OLED_Display_Temp__MCP9809__default_image__DDS6wMG)


#Add objcopy steps
OLED_Display_Temp__MCP9809__default_objcopy_avr_rule(OLED_Display_Temp__MCP9809__default_image__DDS6wMG)

