include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(led_blinking_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(led_blinking_default_default_XC8_FILE_TYPE_assemble)
add_library(led_blinking_default_default_XC8_assemble OBJECT ${led_blinking_default_default_XC8_FILE_TYPE_assemble})
    led_blinking_default_default_XC8_assemble_rule(led_blinking_default_default_XC8_assemble)
    list(APPEND led_blinking_default_library_list "$<TARGET_OBJECTS:led_blinking_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(led_blinking_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(led_blinking_default_default_XC8_assemblePreprocess OBJECT ${led_blinking_default_default_XC8_FILE_TYPE_assemblePreprocess})
    led_blinking_default_default_XC8_assemblePreprocess_rule(led_blinking_default_default_XC8_assemblePreprocess)
    list(APPEND led_blinking_default_library_list "$<TARGET_OBJECTS:led_blinking_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(led_blinking_default_default_XC8_FILE_TYPE_compile)
add_library(led_blinking_default_default_XC8_compile OBJECT ${led_blinking_default_default_XC8_FILE_TYPE_compile})
    led_blinking_default_default_XC8_compile_rule(led_blinking_default_default_XC8_compile)
    list(APPEND led_blinking_default_library_list "$<TARGET_OBJECTS:led_blinking_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(led_blinking_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(led_blinking_default_default_XC8_objcopy_avr OBJECT ${led_blinking_default_default_XC8_FILE_TYPE_objcopy_avr})
    led_blinking_default_default_XC8_objcopy_avr_rule(led_blinking_default_default_XC8_objcopy_avr)
    list(APPEND led_blinking_default_library_list "$<TARGET_OBJECTS:led_blinking_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(led_blinking_default_image_iiIh6LKd ${led_blinking_default_library_list})

set_target_properties(led_blinking_default_image_iiIh6LKd PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${led_blinking_default_output_dir}")
target_link_libraries(led_blinking_default_image_iiIh6LKd PRIVATE ${led_blinking_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
led_blinking_default_link_rule( led_blinking_default_image_iiIh6LKd)


#Add objcopy steps
led_blinking_default_objcopy_avr_rule(led_blinking_default_image_iiIh6LKd)
add_custom_target(
    merge_loadable_files ALL
    COMMAND hexmate  c:/Users/yashs/Desktop/PIC Microcontrollers/ATmega4809-CNANO/Code Example/ATmega4809_LED_Blink.X/dist/default/production/ATmega4809_LED_Blink.X.production.hex "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/led_blinking/default.hex"  -O"${CMAKE_CURRENT_SOURCE_DIR}/../../../out/led_blinking/default-unified.hex"
    BYPRODUCTS "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/led_blinking/default-unified.hex"
    COMMENT "Merging loadable hex files into unified image")
add_dependencies(merge_loadable_files led_blinking_default_image_iiIh6LKd)

