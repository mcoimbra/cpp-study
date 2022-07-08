# Add this compile definition for Debug builds, this same logic works for
# target_compile_options, target_link_options, etc.
#[[target_compile_definitions(hello_world PRIVATE
    $<$<CONFIG:Debug>:
        FOOBAR_DEBUG=1
    >
)]]

add_executable(numeric_limits_example numeric_limits_example.cpp)
#target_compile_features(app PRIVATE cxx_std_17)
