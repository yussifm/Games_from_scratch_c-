#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2_ttf::SDL2_ttf" for configuration "Debug"
set_property(TARGET SDL2_ttf::SDL2_ttf APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL2_ttf::SDL2_ttf PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/SDL2_ttfd.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "SDL2::SDL2"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/SDL2_ttfd.dll"
  )

list(APPEND _cmake_import_check_targets SDL2_ttf::SDL2_ttf )
list(APPEND _cmake_import_check_files_for_SDL2_ttf::SDL2_ttf "${_IMPORT_PREFIX}/debug/lib/SDL2_ttfd.lib" "${_IMPORT_PREFIX}/debug/bin/SDL2_ttfd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
