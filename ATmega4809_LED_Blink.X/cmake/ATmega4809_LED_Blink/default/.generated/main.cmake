include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(ATmega4809_LED_Blink_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_assemble)
add_library(ATmega4809_LED_Blink_default_default_XC8_assemble OBJECT ${ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_assemble})
    ATmega4809_LED_Blink_default_default_XC8_assemble_rule(ATmega4809_LED_Blink_default_default_XC8_assemble)
    list(APPEND ATmega4809_LED_Blink_default_library_list "$<TARGET_OBJECTS:ATmega4809_LED_Blink_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(ATmega4809_LED_Blink_default_default_XC8_assemblePreprocess OBJECT ${ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_assemblePreprocess})
    ATmega4809_LED_Blink_default_default_XC8_assemblePreprocess_rule(ATmega4809_LED_Blink_default_default_XC8_assemblePreprocess)
    list(APPEND ATmega4809_LED_Blink_default_library_list "$<TARGET_OBJECTS:ATmega4809_LED_Blink_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_compile)
add_library(ATmega4809_LED_Blink_default_default_XC8_compile OBJECT ${ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_compile})
    ATmega4809_LED_Blink_default_default_XC8_compile_rule(ATmega4809_LED_Blink_default_default_XC8_compile)
    list(APPEND ATmega4809_LED_Blink_default_library_list "$<TARGET_OBJECTS:ATmega4809_LED_Blink_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(ATmega4809_LED_Blink_default_default_XC8_objcopy_avr OBJECT ${ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_objcopy_avr})
    ATmega4809_LED_Blink_default_default_XC8_objcopy_avr_rule(ATmega4809_LED_Blink_default_default_XC8_objcopy_avr)
    list(APPEND ATmega4809_LED_Blink_default_library_list "$<TARGET_OBJECTS:ATmega4809_LED_Blink_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(ATmega4809_LED_Blink_default_image_lLFFBc4H ${ATmega4809_LED_Blink_default_library_list})

set_target_properties(ATmega4809_LED_Blink_default_image_lLFFBc4H PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${ATmega4809_LED_Blink_default_output_dir}")
target_link_libraries(ATmega4809_LED_Blink_default_image_lLFFBc4H PRIVATE ${ATmega4809_LED_Blink_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
ATmega4809_LED_Blink_default_link_rule( ATmega4809_LED_Blink_default_image_lLFFBc4H)


#Add objcopy steps
ATmega4809_LED_Blink_default_objcopy_avr_rule(ATmega4809_LED_Blink_default_image_lLFFBc4H)

