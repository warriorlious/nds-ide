//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_alarm.cpp'                          *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h16'35"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 820
  #error "This file has been compiled with a version of GALGAS that uses libpm version 820, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_alarm.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_alarm.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'alarm'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_i0_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_alarm_map  &var_cas_alarms) {
  GGS_lstring  var_cas_alarm_name ;
  GGS_alarm_obj  var_cas_alarm ;
  GGS_action_obj  var_cas_alarm_action ;
  GGS_autostart_obj  var_cas_alarm_autostart ;
  GGS_lstring  var_cas_counter_name ;
  GGS_lstringlist  var_cas_acc_apps ;
  GGS_lstring  var_cas_desc ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARM) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_5F_token (var_cas_alarm_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  const GGS_bool cond_1736 = var_cas_alarms.reader_hasKey (var_cas_alarm_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (75))) ;
  if (cond_1736.isBuiltAndTrue ()) {
    var_cas_alarms.modifier_del (inLexique, var_cas_alarm_name, var_cas_alarm COMMA_SOURCE_FILE_AT_LINE (76)) ;
    var_cas_alarm_action = var_cas_alarm.reader_action_params (inLexique COMMA_SOURCE_FILE_AT_LINE (77)) ;
    var_cas_alarm_autostart = var_cas_alarm.reader_autostart_params (inLexique COMMA_SOURCE_FILE_AT_LINE (78)) ;
    var_cas_counter_name = var_cas_alarm.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (79)) ;
    var_cas_acc_apps = var_cas_alarm.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (80)) ;
    var_cas_desc = var_cas_alarm.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (81)) ;
  }else if (cond_1736.isBuiltAndFalse ()) {
    var_cas_alarm_action = GGS_void_action ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (83)) ;
    var_cas_alarm_autostart = GGS_autostart_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (84)) ;
    var_cas_counter_name = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (85)) ;
    var_cas_acc_apps = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (87)) ;
    var_cas_alarm = GGS_alarm_obj ::constructor_new (inLexique, var_cas_desc, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps COMMA_SOURCE_FILE_AT_LINE (88)) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  nt_alarm_5F_parameters_ (inLexique, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  var_cas_alarm = GGS_alarm_obj ::constructor_new (inLexique, var_cas_desc, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps COMMA_SOURCE_FILE_AT_LINE (97)) ;
  var_cas_alarms.modifier_put (inLexique, var_cas_alarm_name, var_cas_alarm COMMA_SOURCE_FILE_AT_LINE (98)) ;
}

//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_i0_parse (C_Lexique_goil_5F_lexique & inLexique) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARM) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  nt_alarm_5F_parameters_parse (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_parse (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  GGS_lstring::constructor_retrieveAndResetTemplateString (inLexique COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of production rule 'alarm_parameters'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_parameters_i1_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_lstring  &var_cas_counter_name,
                                GGS_action_obj  &var_cas_alarm_action,
                                GGS_autostart_obj  &var_cas_alarm_autostart,
                                GGS_lstringlist  &var_cas_acc_apps) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_alarm_0 (inLexique)) {
        case 2 : {
          const GGS_bool cond_2707 = (var_cas_counter_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (109))).operator_isNotEqual (GGS_string ("")) ;
          if (cond_2707.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("COUNTER attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (111)) ;
            var_cas_counter_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (111)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (112)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COUNTER) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_counter_name) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_2777_0 ;
          nt_description_ (inLexique, automatic_var_2777_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 3 : {
          { const GGS_action_obj _var_3001 = var_cas_alarm_action ; // CAST instruction
            if (_var_3001.getPtr () != NULL) {
              macroValidPointer (_var_3001.getPtr ()) ;
              if (typeid (cPtr_void_action) == typeid (* (_var_3001.getPtr ()))) {
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ACTION attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (119)) ;
                var_cas_alarm_action.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (119)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (120)) ;
              }
            }
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACTION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          nt_alarm_5F_action_5F_params_ (inLexique, var_cas_alarm_action) ;
          GGS_lstring  automatic_var_3090_0 ;
          nt_description_ (inLexique, automatic_var_3090_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          { const GGS_autostart_obj _var_3326 = var_cas_alarm_autostart ; // CAST instruction
            if (_var_3326.getPtr () != NULL) {
              macroValidPointer (_var_3326.getPtr ()) ;
              if (typeid (cPtr_autostart_void) == typeid (* (_var_3326.getPtr ()))) {
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSTART attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (127)) ;
                var_cas_alarm_autostart.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (127)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (128)) ;
              }
            }
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTOSTART) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_alarm_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
              nt_alarm_5F_autostart_5F_params_ (inLexique, var_cas_alarm_autostart) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_HERE) ;
              var_cas_alarm_autostart = GGS_autostart_false ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (136)) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_3572_0 ;
          nt_description_ (inLexique, automatic_var_3572_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_lstring  var_cas_app ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACCESSING_5F_APPLICATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_app) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_3672_0 ;
          nt_description_ (inLexique, automatic_var_3672_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_acc_apps,  var_cas_app,  GGS_string ("ACCESSING_APPLICATION") COMMA_SOURCE_FILE_AT_LINE (142)) ;
          } break ;
        case 6 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_alarm_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_parameters_i1_parse (C_Lexique_goil_5F_lexique & inLexique) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_alarm_0 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COUNTER) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 3 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACTION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          nt_alarm_5F_action_5F_params_parse (inLexique) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTOSTART) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_alarm_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
              nt_alarm_5F_autostart_5F_params_parse (inLexique) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACCESSING_5F_APPLICATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 6 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_alarm_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  GGS_lstring::constructor_retrieveAndResetTemplateString (inLexique COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of production rule 'alarm_action_params'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_action_5F_params_i2_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_action_obj  &var_cas_alarm_action) {
  switch (select_goil_5F_obj_5F_alarm_3 (inLexique)) {
    case 1 : {
      GGS_lstring  var_cas_task_name = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (152)) ;
      GGS_lstring  var_cas_event_name = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (153)) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_SETEVENT) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      { bool syntaxRepeat_4 = true ;
        while (syntaxRepeat_4) {
          switch (select_goil_5F_obj_5F_alarm_4 (inLexique)) {
            case 2 : {
              const GGS_bool cond_4268 = (var_cas_task_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (157))).operator_isNotEqual (GGS_string ("")) ;
              if (cond_4268.isBuiltAndTrue ()) {
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TASK attribute already defined for this alarm action") COMMA_SOURCE_FILE_AT_LINE (159)) ;
                var_cas_task_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (159)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (160)) ;
              }
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TASK) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.assignFromAttribute_att_5F_token (var_cas_task_name) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              GGS_lstring  automatic_var_4350_0 ;
              nt_description_ (inLexique, automatic_var_4350_0) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              } break ;
            case 3 : {
              const GGS_bool cond_4565 = (var_cas_event_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (166))).operator_isNotEqual (GGS_string ("")) ;
              if (cond_4565.isBuiltAndTrue ()) {
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EVENT attribute already defined for this alarm action") COMMA_SOURCE_FILE_AT_LINE (168)) ;
                var_cas_event_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (168)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (169)) ;
              }
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_EVENT) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.assignFromAttribute_att_5F_token (var_cas_event_name) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              GGS_lstring  automatic_var_4649_0 ;
              nt_description_ (inLexique, automatic_var_4649_0) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              } break ;
            default :
              syntaxRepeat_4 = false ;
              break ;
          }
        }
      }
      var_cas_alarm_action = GGS_setevent_action ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task_name, var_cas_event_name COMMA_SOURCE_FILE_AT_LINE (175)) ;
      } break ;
    case 2 : {
      GGS_lstring  var_cas_task_name ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACTIVATETASK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TASK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.assignFromAttribute_att_5F_token (var_cas_task_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
      GGS_lstring  automatic_var_4864_0 ;
      nt_description_ (inLexique, automatic_var_4864_0) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      var_cas_alarm_action = GGS_activatetask_action ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task_name COMMA_SOURCE_FILE_AT_LINE (181)) ;
      } break ;
    case 3 : {
      const GGS_bool cond_5086 = gOption_goil_5F_options_autosar_5F_on.reader_value () ;
      if (cond_5086.isBuiltAndTrue ()) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is on. AUTOSAR spec does not allow alarm callback") COMMA_SOURCE_FILE_AT_LINE (185)) ;
      }
      GGS_lstring  var_cas_function_name ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMCALLBACK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMCALLBACKNAME) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.assignFromAttribute_a_5F_string (var_cas_function_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_HERE) ;
      GGS_lstring  automatic_var_5229_0 ;
      nt_description_ (inLexique, automatic_var_5229_0) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      var_cas_alarm_action = GGS_callback_action ::constructor_new (inLexique, GGS_location (inLexique), var_cas_function_name COMMA_SOURCE_FILE_AT_LINE (190)) ;
      } break ;
    case 4 : {
      const GGS_bool cond_5474 = (gOption_goil_5F_options_autosar_5F_on.reader_value ()).operator_isEqual (GGS_bool (false)) ;
      if (cond_5474.isBuiltAndTrue ()) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off. Turn it on to allow an INCREMENTCOUNTER action in alarm") COMMA_SOURCE_FILE_AT_LINE (194)) ;
      }
      GGS_lstring  var_cas_counter_name ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INCREMENTCOUNTER) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COUNTER) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.assignFromAttribute_att_5F_token (var_cas_counter_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
      GGS_lstring  automatic_var_5605_0 ;
      nt_description_ (inLexique, automatic_var_5605_0) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      var_cas_alarm_action = GGS_incrementcounter_action ::constructor_new (inLexique, GGS_location (inLexique), var_cas_counter_name COMMA_SOURCE_FILE_AT_LINE (199)) ;
      } break ;
    default :
      break ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_action_5F_params_i2_parse (C_Lexique_goil_5F_lexique & inLexique) {
  switch (select_goil_5F_obj_5F_alarm_3 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_SETEVENT) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      { bool syntaxRepeat_4 = true ;
        while (syntaxRepeat_4) {
          switch (select_goil_5F_obj_5F_alarm_4 (inLexique)) {
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TASK) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              nt_description_parse (inLexique) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              } break ;
            case 3 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_EVENT) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              nt_description_parse (inLexique) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              } break ;
            default :
              syntaxRepeat_4 = false ;
              break ;
          }
        }
      }
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACTIVATETASK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TASK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
      nt_description_parse (inLexique) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      } break ;
    case 3 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMCALLBACK) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMCALLBACKNAME) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_HERE) ;
      nt_description_parse (inLexique) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      } break ;
    case 4 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INCREMENTCOUNTER) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COUNTER) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
      nt_description_parse (inLexique) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  GGS_lstring::constructor_retrieveAndResetTemplateString (inLexique COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of production rule 'alarm_autostart_params'         *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_autostart_5F_params_i3_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_autostart_obj  &var_cas_alarm_autostart) {
  GGS_bool var_cas_alarm_time_known = GGS_bool (false) ;
  GGS_bool var_cas_cycle_time_known = GGS_bool (false) ;
  GGS_luint64  var_cas_alarm_time = GGS_luint64 ::constructor_new (inLexique, GGS_uint64 (0ULL), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (210)) ;
  GGS_luint64  var_cas_cycle_time = GGS_luint64 ::constructor_new (inLexique, GGS_uint64 (0ULL), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (211)) ;
  GGS_lstring  var_cas_app_mode = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (212)) ;
  GGS_stringset  var_cas_app_modes = GGS_stringset ::constructor_emptySet () ;
  { bool syntaxRepeat_5 = true ;
    while (syntaxRepeat_5) {
      switch (select_goil_5F_obj_5F_alarm_5 (inLexique)) {
        case 2 : {
          const GGS_bool cond_6279 = var_cas_alarm_time_known ;
          if (cond_6279.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ALARMTIME attribute already defined for this alarm autostart") COMMA_SOURCE_FILE_AT_LINE (219)) ;
            var_cas_alarm_time.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (219)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (220)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_alarm_time) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_6355_0 ;
          nt_description_ (inLexique, automatic_var_6355_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          var_cas_alarm_time_known = GGS_bool (true) ;
          } break ;
        case 3 : {
          const GGS_bool cond_6589 = var_cas_cycle_time_known ;
          if (cond_6589.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("CYCLETIME attribute already defined for this alarm autostart") COMMA_SOURCE_FILE_AT_LINE (226)) ;
            var_cas_cycle_time.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (226)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (227)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CYCLETIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_cycle_time) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_6665_0 ;
          nt_description_ (inLexique, automatic_var_6665_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          var_cas_cycle_time_known = GGS_bool (true) ;
          } break ;
        case 4 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_APPMODE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_app_mode) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_6769_0 ;
          nt_description_ (inLexique, automatic_var_6769_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          var_cas_app_modes.addAssign_operation (var_cas_app_mode.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (232))) ;
          } break ;
        default :
          syntaxRepeat_5 = false ;
          break ;
      }
    }
  }
  const GGS_bool cond_6977 = (var_cas_alarm_time_known).operator_not () ;
  if (cond_6977.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ALARMTIME attribute is missing") COMMA_SOURCE_FILE_AT_LINE (238)) ;
  }
  var_cas_alarm_autostart = GGS_alarm_autostart_true ::constructor_new (inLexique, GGS_location (inLexique), var_cas_alarm_time, var_cas_cycle_time, var_cas_app_modes COMMA_SOURCE_FILE_AT_LINE (239)) ;
}

//---------------------------------------------------------------------------*

void goil_obj_alarm::rule_goil_5F_obj_5F_alarm_alarm_5F_autostart_5F_params_i3_parse (C_Lexique_goil_5F_lexique & inLexique) {
  { bool syntaxRepeat_5 = true ;
    while (syntaxRepeat_5) {
      switch (select_goil_5F_obj_5F_alarm_5 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ALARMTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 3 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CYCLETIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_APPMODE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_5 = false ;
          break ;
      }
    }
  }
  GGS_lstring::constructor_retrieveAndResetTemplateString (inLexique COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

