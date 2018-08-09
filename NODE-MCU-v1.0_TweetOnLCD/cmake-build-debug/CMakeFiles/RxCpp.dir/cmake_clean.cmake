file(REMOVE_RECURSE
  "libRxCpp.pdb"
  "libRxCpp.dll"
  "libRxCpp.dll.a"
  "libRxCpp.dll.manifest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/RxCpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
