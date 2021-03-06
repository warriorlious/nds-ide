//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'defaults.h'                              *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h16'12"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef defaults_DEFINED
#define defaults_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_check.h"
#include "goil_options.h"
#include "goil_semantic_types.h"
#include "goil_types_root.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'check_custom_field'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_custom_field (C_Compiler &,
                                GGS_ident_map  &,
                                GGS_lstring  ,
                                GGS_imp_type   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'check_range'                            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_range (C_Compiler &,
                                GGS_basic_type  ,
                                GGS_imp_type   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Routine 'verify_and_set_tasks_defaults'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_and_set_tasks_defaults (C_Compiler &,
                                GGS_task_map  &,
                                GGS_implementation_spec   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'verify_and_set_isrs_defaults'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_and_set_isrs_defaults (C_Compiler &,
                                GGS_isr_map  &,
                                GGS_implementation_spec   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'add_system_counter'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_system_counter (C_Compiler &,
                                GGS_root_obj  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'set_defaults'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_set_defaults (C_Compiler &,
                                const GGS_implementation  ,
                                GGS_root_obj  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif
