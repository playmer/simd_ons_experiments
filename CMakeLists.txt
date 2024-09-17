cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(simd_test LANGUAGES C CXX)

# Determine what architecture we're targeting.
include(cmake/TargetArch.cmake)
target_architecture(ONS_TARGET_ARCH)
message(STATUS "Target Architecture: ${ONS_TARGET_ARCH}")

add_executable(simd_test "")

set(ONS_X86_MMX_AVAILIBLE 0)
set(ONS_X86_SSE_AVAILIBLE 0)
set(ONS_X86_SSE2_AVAILIBLE 0)
set(ONS_X86_SSE3_AVAILIBLE 0)
set(ONS_X86_SSSE3_AVAILIBLE 0)
set(ONS_X86_SSE4_1_AVAILIBLE 0)
set(ONS_X86_SSE4_2_AVAILIBLE 0)
set(ONS_X86_AVX_AVAILIBLE 0)
set(ONS_X86_AVX2_AVAILIBLE 0)
set(ONS_PPC_ALTIVEC_AVAILIBLE 0)
set(ONS_ARM_NEON_AVAILIBLE 0)
set(ONS_ARM_SVE_AVAILIBLE 0)
set(ONS_ARM_SVE2_AVAILIBLE 0)

if (${ONS_TARGET_ARCH} STREQUAL "x86_64")    
    if (NOT MSVC)
        set(ONS_X86_MMX_AVAILIBLE 1)
    endif()
    
    set(ONS_X86_SSE_AVAILIBLE 1)
    set(ONS_X86_SSE2_AVAILIBLE 1)
    set(ONS_X86_SSE3_AVAILIBLE 1)
    set(ONS_X86_SSSE3_AVAILIBLE 1)
    set(ONS_X86_SSE4_1_AVAILIBLE 1)
    set(ONS_X86_SSE4_2_AVAILIBLE 1)
    set(ONS_X86_AVX_AVAILIBLE 1)
    set(ONS_X86_AVX2_AVAILIBLE 1)

    if(ONS_COMPILER_FLAG_STYLE STREQUAL "GNU")
        set_source_files_properties(
            graphics_sse2.cpp
            COMPILE_OPTIONS -msse2
        )
        
        set_source_files_properties(
            graphics_mmx.cpp
            COMPILE_OPTIONS -mmmx
        )
    endif()
elseif(${ONS_TARGET_ARCH} STREQUAL "i386")
    
    set(ONS_X86_MMX_AVAILIBLE 1)
    set(ONS_X86_SSE_AVAILIBLE 1)
    set(ONS_X86_SSE2_AVAILIBLE 1)

    if(ONS_COMPILER_FLAG_STYLE STREQUAL "GNU")
        set_source_files_properties(
            graphics_sse2.cpp
            COMPILE_OPTIONS -msse2
        )
        
        set_source_files_properties(
            graphics_mmx.cpp
            COMPILE_OPTIONS -mmmx
        )
    endif()
elseif(${ONS_TARGET_ARCH} STREQUAL "ppc" OR ${ONS_TARGET_ARCH} STREQUAL "ppc"
        AND NOT "${CMAKE_SYSTEM_NAME}" STREQUAL "NintendoWii"
        AND NOT "${CMAKE_SYSTEM_NAME}" STREQUAL "NintendoGameCube")
    set(ONS_PPC_ALTIVEC_AVAILIBLE 1)
    
    set_source_files_properties(
        graphics_altivec.cpp
        COMPILE_OPTIONS -maltivec
    )
elseif(${ONS_TARGET_ARCH} STREQUAL "armv9" OR
       ${ONS_TARGET_ARCH} STREQUAL "armv8" OR
       ${ONS_TARGET_ARCH} STREQUAL "armv7" OR
       ${ONS_TARGET_ARCH} STREQUAL "armv6" OR
       ${ONS_TARGET_ARCH} STREQUAL "armv5" OR
       ${ONS_TARGET_ARCH} STREQUAL "arm")

    set(ONS_ARM_NEON_AVAILIBLE 1)
    if (NOT MSVC)
        set(ONS_ARM_SVE_AVAILIBLE 1)
        set(ONS_ARM_SVE2_AVAILIBLE 1)
    endif()
endif()


target_compile_definitions(simd_test
PRIVATE
    ONS_X86_MMX_AVAILIBLE=${ONS_X86_MMX_AVAILIBLE}
    ONS_X86_SSE_AVAILIBLE=${ONS_X86_SSE_AVAILIBLE}
    ONS_X86_SSE2_AVAILIBLE=${ONS_X86_SSE2_AVAILIBLE}
    ONS_X86_SSE3_AVAILIBLE=${ONS_X86_SSE3_AVAILIBLE}
    ONS_X86_SSSE3_AVAILIBLE=${ONS_X86_SSSE3_AVAILIBLE}
    ONS_X86_SSE4_1_AVAILIBLE=${ONS_X86_SSE4_1_AVAILIBLE}
    ONS_X86_SSE4_2_AVAILIBLE=${ONS_X86_SSE4_2_AVAILIBLE}
    ONS_X86_AVX_AVAILIBLE=${ONS_X86_AVX_AVAILIBLE}
    ONS_X86_AVX2_AVAILIBLE=${ONS_X86_AVX2_AVAILIBLE}
    ONS_PPC_ALTIVEC_AVAILIBLE=${ONS_PPC_ALTIVEC_AVAILIBLE}
    ONS_ARM_NEON_AVAILIBLE=${ONS_ARM_NEON_AVAILIBLE}
    ONS_ARM_SVE_AVAILIBLE=${ONS_ARM_SVE_AVAILIBLE}
    ONS_ARM_SVE2_AVAILIBLE=${ONS_ARM_SVE2_AVAILIBLE}
)

message(STATUS "ONS_X86_MMX_AVAILIBLE=${ONS_X86_MMX_AVAILIBLE}")
message(STATUS "ONS_X86_SSE_AVAILIBLE=${ONS_X86_SSE_AVAILIBLE}")
message(STATUS "ONS_X86_SSE2_AVAILIBLE=${ONS_X86_SSE2_AVAILIBLE}")
message(STATUS "ONS_X86_SSE3_AVAILIBLE=${ONS_X86_SSE3_AVAILIBLE}")
message(STATUS "ONS_X86_SSSE3_AVAILIBLE=${ONS_X86_SSSE3_AVAILIBLE}")
message(STATUS "ONS_X86_SSE4_1_AVAILIBLE=${ONS_X86_SSE4_1_AVAILIBLE}")
message(STATUS "ONS_X86_SSE4_2_AVAILIBLE=${ONS_X86_SSE4_2_AVAILIBLE}")
message(STATUS "ONS_X86_AVX_AVAILIBLE=${ONS_X86_AVX_AVAILIBLE}")
message(STATUS "ONS_X86_AVX2_AVAILIBLE=${ONS_X86_AVX2_AVAILIBLE}")
message(STATUS "ONS_PPC_ALTIVEC_AVAILIBLE=${ONS_PPC_ALTIVEC_AVAILIBLE}")
message(STATUS "ONS_ARM_NEON_AVAILIBLE=${ONS_ARM_NEON_AVAILIBLE}")
message(STATUS "ONS_ARM_SVE_AVAILIBLE=${ONS_ARM_SVE_AVAILIBLE}")
message(STATUS "ONS_ARM_SVE2_AVAILIBLE=${ONS_ARM_SVE2_AVAILIBLE}")


target_compile_definitions(simd_test PRIVATE USE_X86_GFX)

target_sources(simd_test
PRIVATE
    graphics_altivec.cpp
    graphics_altivec.h
    graphics_blend.h
    graphics_common.h
    graphics_cpu.h
    graphics_mmx.cpp
    graphics_mmx.h
    graphics_neon.cpp
    graphics_neon.h
    graphics_resize.h
    graphics_routines.cpp
    graphics_sse2.cpp
    graphics_sse2.h
    graphics_sum.h
    main.cpp
)