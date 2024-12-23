#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::brotli::brotlienc" for configuration "Debug"
set_property(TARGET unofficial::brotli::brotlienc APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(unofficial::brotli::brotlienc PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/brotlienc.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/brotlienc.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::brotli::brotlienc )
list(APPEND _cmake_import_check_files_for_unofficial::brotli::brotlienc "${_IMPORT_PREFIX}/lib/brotlienc.lib" "${_IMPORT_PREFIX}/bin/brotlienc.dll" )

# Import target "unofficial::brotli::brotlidec" for configuration "Debug"
set_property(TARGET unofficial::brotli::brotlidec APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(unofficial::brotli::brotlidec PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/brotlidec.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/brotlidec.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::brotli::brotlidec )
list(APPEND _cmake_import_check_files_for_unofficial::brotli::brotlidec "${_IMPORT_PREFIX}/lib/brotlidec.lib" "${_IMPORT_PREFIX}/bin/brotlidec.dll" )

# Import target "unofficial::brotli::brotlicommon" for configuration "Debug"
set_property(TARGET unofficial::brotli::brotlicommon APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(unofficial::brotli::brotlicommon PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/brotlicommon.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/brotlicommon.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::brotli::brotlicommon )
list(APPEND _cmake_import_check_files_for_unofficial::brotli::brotlicommon "${_IMPORT_PREFIX}/lib/brotlicommon.lib" "${_IMPORT_PREFIX}/bin/brotlicommon.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
