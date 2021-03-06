//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_imp_def.h'                            *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h16'11"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_imp_def_DEFINED
#define goil_imp_def_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_check.h"
#include "goil_options.h"
#include "goil_routines.h"
#include "goil_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                  Parser class goil_imp_def declaration                    *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_imp_def {
  public : virtual ~goil_imp_def (void) {}

  protected : virtual void nt_implementation_5F_definition_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_implementation_5F_spec_5F_list_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_implementation_5F_spec_5F_list_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_implementation_5F_spec_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_implementation_5F_spec_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_implementation_5F_list_ (C_Lexique_goil_5F_lexique &,
                                GGS_string ,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_impl_5F_attr_5F_def_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) = 0 ;

  protected : virtual void nt_impl_5F_attr_5F_def_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_auto_5F_specifier_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &) = 0 ;

  protected : virtual void nt_auto_5F_specifier_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_uint_33__32__5F_attribute_5F_name_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_uint_33__32__5F_attribute_5F_name_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_attribute_5F_name_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_attribute_5F_name_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_multiple_5F_specifier_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &) = 0 ;

  protected : virtual void nt_multiple_5F_specifier_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_default_5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_default_5F_number_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_default_5F_name_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_default_5F_name_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_enumeration_ (C_Lexique_goil_5F_lexique &,
                                GGS_stringset  &) = 0 ;

  protected : virtual void nt_enumeration_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_enumerator_ (C_Lexique_goil_5F_lexique &,
                                GGS_stringset  &) = 0 ;

  protected : virtual void nt_enumerator_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_impl_5F_parameter_5F_list_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_impl_5F_parameter_5F_list_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_implementation_5F_def_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_implementation_5F_def_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_uint_33__32__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint32_set  &) = 0 ;

  protected : virtual void nt_uint_33__32__5F_number_5F_set_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_sint_33__32__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint32_set  &) = 0 ;

  protected : virtual void nt_sint_33__32__5F_number_5F_set_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_uint_36__34__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint64_set  &) = 0 ;

  protected : virtual void nt_sint_36__34__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64_set  &) = 0 ;

  protected : virtual void nt_float_5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                GGS_float_set  &) = 0 ;

  protected : virtual void nt_default_5F_uint_33__32__5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint32_class  &) = 0 ;

  protected : virtual void nt_default_5F_uint_33__32__5F_number_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_default_5F_sint_33__32__5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint32_class  &) = 0 ;

  protected : virtual void nt_default_5F_sint_33__32__5F_number_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_default_5F_uint_36__34__5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint64_class  &) = 0 ;

  protected : virtual void nt_default_5F_sint_36__34__5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64_class  &) = 0 ;

  protected : virtual void nt_default_5F_float_5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_float_class  &) = 0 ;

  protected : virtual void nt_default_5F_string_ (C_Lexique_goil_5F_lexique &,
                                GGS_string_class  &) = 0 ;

  protected : virtual void nt_default_5F_enum_ (C_Lexique_goil_5F_lexique &,
                                GGS_basic_type  &) = 0 ;

  protected : virtual void nt_default_5F_bool_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool_class  &) = 0 ;

  protected : virtual void nt_signed_5F_number_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64  &) = 0 ;

  protected : virtual void nt_signed_5F_number_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_definition_i0_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_definition_i0_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_spec_5F_list_i1_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_spec_5F_list_i1_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_spec_i2_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_spec_i2_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_list_i3_ (C_Lexique_goil_5F_lexique &,
                                GGS_string ,
                                GGS_implementation  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_list_i3_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i4_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i4_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i5_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i5_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i6_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i6_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i7_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i7_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i8_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i8_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i9_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_imp_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_attr_5F_def_i9_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_auto_5F_specifier_i10_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_auto_5F_specifier_i10_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_uint_33__32__5F_number_5F_set_i11_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint32_set  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_6 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_7 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_uint_33__32__5F_number_5F_set_i11_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_sint_33__32__5F_number_5F_set_i12_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint32_set  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_8 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_9 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_10 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_11 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_12 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_sint_33__32__5F_number_5F_set_i12_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_uint_36__34__5F_number_5F_set_i13_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint64_set  &) ;

  protected : void rule_goil_5F_imp_5F_def_sint_36__34__5F_number_5F_set_i14_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64_set  &) ;

  protected : void rule_goil_5F_imp_5F_def_float_5F_number_5F_set_i15_ (C_Lexique_goil_5F_lexique &,
                                GGS_float_set  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_uint_33__32__5F_number_i16_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint32_class  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_13 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_14 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_uint_33__32__5F_number_i16_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_sint_33__32__5F_number_i17_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint32_class  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_15 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_16 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_sint_33__32__5F_number_i17_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_uint_36__34__5F_number_i18_ (C_Lexique_goil_5F_lexique &,
                                GGS_uint64_class  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_sint_36__34__5F_number_i19_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64_class  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_float_5F_number_i20_ (C_Lexique_goil_5F_lexique &,
                                GGS_float_class  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_string_i21_ (C_Lexique_goil_5F_lexique &,
                                GGS_string_class  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_enum_i22_ (C_Lexique_goil_5F_lexique &,
                                GGS_basic_type  &) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_bool_i23_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool_class  &) ;

  protected : void rule_goil_5F_imp_5F_def_signed_5F_number_i24_ (C_Lexique_goil_5F_lexique &,
                                GGS_sint64  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_17 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_signed_5F_number_i24_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_uint_33__32__5F_attribute_5F_name_i25_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_18 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_uint_33__32__5F_attribute_5F_name_i25_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_attribute_5F_name_i26_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_19 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_attribute_5F_name_i26_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_multiple_5F_specifier_i27_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_20 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_multiple_5F_specifier_i27_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_number_i28_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &,
                                GGS_luint64  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_21 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_number_i28_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_name_i29_ (C_Lexique_goil_5F_lexique &,
                                GGS_bool &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_22 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_default_5F_name_i29_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_enumeration_i30_ (C_Lexique_goil_5F_lexique &,
                                GGS_stringset  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_23 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_enumeration_i30_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_enumerator_i31_ (C_Lexique_goil_5F_lexique &,
                                GGS_stringset  &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_24 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_enumerator_i31_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_parameter_5F_list_i32_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_25 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_imp_5F_def_26 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_imp_5F_def_impl_5F_parameter_5F_list_i32_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_def_i33_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_imp_5F_def_implementation_5F_def_i33_parse (C_Lexique_goil_5F_lexique & inLexique) ;

} ;

//---------------------------------------------------------------------------*

#endif
