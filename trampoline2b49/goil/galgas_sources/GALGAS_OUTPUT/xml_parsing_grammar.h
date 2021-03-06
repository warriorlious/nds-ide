//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'xml_parsing_grammar.h'                        *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h44'46"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_xml_parsing_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_xml_parsing_grammar_HAS_BEEN_DEFINED

//---------------------------------------------------------------------------*

#include "xml_parsing_syntax.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class xml_parsing_grammar : public xml_parsing_syntax {
  public : virtual void nt_element_ (xml_parsing_lexique &,
                                GGS_xmlNodeList &,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_string) ;
  public : virtual void nt_element_list_ (xml_parsing_lexique &,
                                GGS_xmlNodeList &,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_string) ;
  public : virtual void nt_start_symbol_ (xml_parsing_lexique &,
                                GGS_xmlNodeList &,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_bool) ;
  public : static void _performSourceFileParsing_ (C_Compiler & _inCompiler,
                                const C_String & _inDependancyExtension,
                                const C_String & _inDependancyPath,
                                GGS_string * _inSentStringPtr,
                                const GGS_lstring inFileName,
                                GGS_xmlNodeList &,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_bool
                                COMMA_LOCATION_ARGS) ;
  public : static void _performSourceStringParsing_ (C_Compiler & _inCompiler,
                                GGS_string * _inSentStringPtr,
                                const GGS_string inSourceString,
                                GGS_xmlNodeList &,
                                const GGS_bool,
                                const GGS_bool,
                                const GGS_bool
                                COMMA_LOCATION_ARGS) ;
  public : virtual sint16 select_repeat_xml_parsing_syntax_0 (xml_parsing_lexique &) ;
  public : virtual sint16 select_repeat_xml_parsing_syntax_1 (xml_parsing_lexique &) ;
  public : virtual sint16 select_repeat_xml_parsing_syntax_2 (xml_parsing_lexique &) ;
  public : virtual sint16 select_xml_parsing_syntax_3 (xml_parsing_lexique &) ;
} ;

//---------------------------------------------------------------------------*

#endif
