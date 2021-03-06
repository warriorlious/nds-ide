//---------------------------------------------------------------------------*
//                                                                           *
//                   File 'goil_template_scanner-cocoa.h'                    *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 15h58'30"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


#import "OC_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    R O U T I N E S                         *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    F U N C T I O N S                       *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N           *
//                                                                           *
//---------------------------------------------------------------------------*

enum {goil_template_scanner_1_,
  goil_template_scanner_1_identifier,
  goil_template_scanner_1_literal_5F_double,
  goil_template_scanner_1_unsigned_5F_literal_5F_integer_36__34_,
  goil_template_scanner_1__2E_,
  goil_template_scanner_1__2E__3D_,
  goil_template_scanner_1__2E__2E__2E_,
  goil_template_scanner_1__3C_,
  goil_template_scanner_1__3C__3D_,
  goil_template_scanner_1__3C__3C_,
  goil_template_scanner_1_string,
  goil_template_scanner_1_comment,
  goil_template_scanner_1_after,
  goil_template_scanner_1_before,
  goil_template_scanner_1_between,
  goil_template_scanner_1_block,
  goil_template_scanner_1_default,
  goil_template_scanner_1_do,
  goil_template_scanner_1_else,
  goil_template_scanner_1_elsif,
  goil_template_scanner_1_emptylist,
  goil_template_scanner_1_end,
  goil_template_scanner_1_error,
  goil_template_scanner_1_exists,
  goil_template_scanner_1_false,
  goil_template_scanner_1_for,
  goil_template_scanner_1_foreach,
  goil_template_scanner_1_from,
  goil_template_scanner_1_here,
  goil_template_scanner_1_if,
  goil_template_scanner_1_in,
  goil_template_scanner_1_let,
  goil_template_scanner_1_loop,
  goil_template_scanner_1_mod,
  goil_template_scanner_1_no,
  goil_template_scanner_1_not,
  goil_template_scanner_1_or,
  goil_template_scanner_1_prefixedby,
  goil_template_scanner_1_template,
  goil_template_scanner_1_templateresult,
  goil_template_scanner_1_then,
  goil_template_scanner_1_to,
  goil_template_scanner_1_true,
  goil_template_scanner_1_yes,
  goil_template_scanner_1_warning,
  goil_template_scanner_1_while,
  goil_template_scanner_1_write,
  goil_template_scanner_1__2A_,
  goil_template_scanner_1__7C_,
  goil_template_scanner_1__2C_,
  goil_template_scanner_1__2B_,
  goil_template_scanner_1__2D__2D_,
  goil_template_scanner_1__3A__3A_,
  goil_template_scanner_1__3E_,
  goil_template_scanner_1__3B_,
  goil_template_scanner_1__3A_,
  goil_template_scanner_1__2D_,
  goil_template_scanner_1__28_,
  goil_template_scanner_1__29_,
  goil_template_scanner_1__2D__3E_,
  goil_template_scanner_1__3F_,
  goil_template_scanner_1__3D__3D_,
  goil_template_scanner_1__3F__3F_,
  goil_template_scanner_1__21_,
  goil_template_scanner_1__3A__3D_,
  goil_template_scanner_1__2B__2B_,
  goil_template_scanner_1__5B_,
  goil_template_scanner_1__5D_,
  goil_template_scanner_1__2B__3D_,
  goil_template_scanner_1__3F__21_,
  goil_template_scanner_1__21__3F_,
  goil_template_scanner_1__2F_,
  goil_template_scanner_1__21__3D_,
  goil_template_scanner_1__3E__3D_,
  goil_template_scanner_1__26_,
  goil_template_scanner_1__7B_,
  goil_template_scanner_1__7D_,
  goil_template_scanner_1__2B__3E_,
  goil_template_scanner_1__2D__3D_,
  goil_template_scanner_1__5E_,
  goil_template_scanner_1__3E__3E_,
  goil_template_scanner_1__7E_,
  goil_template_scanner_1__3C__2D_
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     S C A N N E R    C L A S S                            *
//                                                                           *
//---------------------------------------------------------------------------*

@interface OC_Lexique_goil_template_scanner : OC_Lexique {
//--- Attributes
  @private NSMutableString * mLexicalAttribute_a_string ;
  @private double mLexicalAttribute_floatValue ;
  @private NSMutableString * mLexicalAttribute_identifierString ;
  @private NSMutableString * mLexicalAttribute_tokenString ;
  @private UInt64 mLexicalAttribute_uint64value ;

}
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


- (UInt32) terminalVocabularyCount ;

- (UInt32) styleIndexForTerminal: (SInt32) inTerminal ;

- (void) parseLexicalTokenForLexicalColoring ;

- (UInt32) styleCount ;

- (NSString *) styleNameForStyleIndex: (SInt32) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (SInt32) inIndex ;

- (BOOL) isTemplateLexique ;
@end

//---------------------------------------------------------------------------*
