# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/flori/esp/idf_5.2/esp-idf/components/bootloader/subproject"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/tmp"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/src/bootloader-stamp"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/src"
  "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/flori/Documents/hapcor/super-dial-motor-knob-screen/idf_code/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
