/*
 * API section for code
 */
#ifdef API_START_SEC_CODE
  #undef API_START_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #error "Starting a .osApiCode while a section is already started"
  #else
    #undef MEMMAP_ERROR
    #pragma ghs section text=".osApiCode"
    #define CURRENT_LINKER_CODE_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_CODE
	#undef API_STOP_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION
  #else
    #error "No section .osApiCode started"
  #endif
#endif

#ifdef API_START_SEC_CONST_UNSPECIFIED
  #undef API_START_SEC_CONST_UNSPECIFIED
  #ifdef CURRENT_LINKER_DATA_SECTION
    #error "Starting a .osApiConst while a section is already started"
  #else
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".osApiConst"
    #define CURRENT_LINKER_DATA_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_CONST_UNSPECIFIED
	#undef API_STOP_SEC_CONST_UNSPECIFIED
  #ifdef CURRENT_LINKER_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_DATA_SECTION
  #else
    #error "No section .osApiConst started"
  #endif
#endif

