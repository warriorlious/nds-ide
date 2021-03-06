//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_obj_networkmessage.h'                      *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h16'55"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_networkmessage_DEFINED
#define goil_obj_networkmessage_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_options.h"
#include "goil_semantics.h"
#include "goil_types_networkmessage.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//             Parser class goil_obj_networkmessage declaration              *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_networkmessage {
  public : virtual ~goil_obj_networkmessage (void) {}

  protected : virtual void nt_networkmess_ (C_Lexique_goil_5F_lexique &,
                                GGS_netmess_map  &) = 0 ;

  protected : virtual void nt_networkmess_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_ipdu_5F_ref_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_ipdu_5F_ref_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_net_5F_messageproperty_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) = 0 ;

  protected : virtual void nt_net_5F_messageproperty_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_static_5F_mp_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) = 0 ;

  protected : virtual void nt_static_5F_mp_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_dynamic_5F_mp_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) = 0 ;

  protected : virtual void nt_dynamic_5F_mp_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_sizeinbits_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_sizeinbits_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_maxsizeinbits_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_maxsizeinbits_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_bitordering_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_bitordering_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_bitposition_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_bitposition_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_datainterpretation_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_datainterpretation_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_initialvalue_ (C_Lexique_goil_5F_lexique &,
                                GGS_basic_type  &) = 0 ;

  protected : virtual void nt_initialvalue_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_direction_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_direction_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_transferproperty_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_transferproperty_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_networkmess_i0_ (C_Lexique_goil_5F_lexique &,
                                GGS_netmess_map  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_networkmess_i0_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_ipdu_5F_ref_i1_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_ipdu_5F_ref_i1_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_net_5F_messageproperty_i2_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_net_5F_messageproperty_i2_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_static_5F_mp_i3_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_static_5F_mp_i3_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_dynamic_5F_mp_i4_ (C_Lexique_goil_5F_lexique &,
                                GGS_base_netprop  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_dynamic_5F_mp_i4_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_sizeinbits_i5_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_sizeinbits_i5_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_maxsizeinbits_i6_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_maxsizeinbits_i6_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_bitordering_i7_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_bitordering_i7_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_bitposition_i8_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_bitposition_i8_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_datainterpretation_i9_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_datainterpretation_i9_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_networkmessage_direction_i10_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_6 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_7 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_networkmessage_direction_i10_parse (C_Lexique_goil_5F_lexique & inLexique) ;

} ;

//---------------------------------------------------------------------------*

#endif
