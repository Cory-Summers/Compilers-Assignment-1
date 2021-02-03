// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "token_parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "token_parser.tab.hh"

// User implementation prologue.

#line 51 "token_parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 30 "token_parser.y" // lalr1.cc:413


  #include "driver-class.hpp"
  #include "context-class.hpp"
  #undef yylex
  #define yylex scanner.yylex

#line 61 "token_parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 3 "token_parser.y" // lalr1.cc:479
namespace  parser  {
#line 147 "token_parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
   TokenParser :: TokenParser  (scanner::TokenLexer & scanner_yyarg, parser::Context & context_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      context (context_yyarg)
  {}

   TokenParser ::~ TokenParser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
   TokenParser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   TokenParser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   TokenParser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
   TokenParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
   TokenParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
   TokenParser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   TokenParser ::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   TokenParser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   TokenParser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
   TokenParser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   TokenParser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   TokenParser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   TokenParser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   TokenParser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   TokenParser ::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
   TokenParser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   TokenParser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   TokenParser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   TokenParser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   TokenParser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   TokenParser ::symbol_number_type
   TokenParser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   TokenParser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   TokenParser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   TokenParser ::stack_symbol_type&
   TokenParser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   TokenParser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
   TokenParser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   TokenParser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   TokenParser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   TokenParser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   TokenParser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   TokenParser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   TokenParser ::debug_level_type
   TokenParser ::debug_level () const
  {
    return yydebug_;
  }

  void
   TokenParser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  TokenParser ::state_type
   TokenParser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   TokenParser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   TokenParser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   TokenParser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, context));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 7:
#line 85 "token_parser.y" // lalr1.cc:859
    { parser::PrintString(context.loc.line, (yystack_[0].value.token));    }
#line 590 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 86 "token_parser.y" // lalr1.cc:859
    { parser::PrintNumber(context.loc.line, (yystack_[0].value.token));    }
#line 596 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 87 "token_parser.y" // lalr1.cc:859
    { parser::PrintChar(context.loc.line, (yystack_[0].value.token));      }
#line 602 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 88 "token_parser.y" // lalr1.cc:859
    { parser::PrintBoolean(context.loc.line, (yystack_[0].value.token));   }
#line 608 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 89 "token_parser.y" // lalr1.cc:859
    { parser::PrintIdentifer(context.loc.line, (yystack_[0].value.token)); }
#line 614 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 92 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, ","); }
#line 620 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 93 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, ":");}
#line 626 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 94 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "[");}
#line 632 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 95 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "]");}
#line 638 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 96 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, ";");}
#line 644 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 97 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "(");}
#line 650 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 98 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, ")");}
#line 656 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 99 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "{");}
#line 662 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 100 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "}");}
#line 668 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 101 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "LEQ"); }
#line 674 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 102 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "<"); }
#line 680 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 103 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, ">"); }
#line 686 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 104 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "GEQ"); }
#line 692 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 105 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "EQ"); }
#line 698 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 106 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "NEQ"); }
#line 704 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 107 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "ADDASS" ); }
#line 710 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 108 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "MINASS" ); }
#line 716 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 109 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "MULASS" ); }
#line 722 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 110 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "DIVASS" ); }
#line 728 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 111 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "MAX"); }
#line 734 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 112 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "MIN"); }
#line 740 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 113 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "-"); }
#line 746 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 114 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "+"); }
#line 752 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 115 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "*"); }
#line 758 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 116 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "/"); }
#line 764 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 117 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "%"); }
#line 770 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 118 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "?"); }
#line 776 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 119 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "=");}
#line 782 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 120 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "--");}
#line 788 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 121 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "++");}
#line 794 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 124 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "IF");}
#line 800 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 125 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "THEN");}
#line 806 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 126 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "ELSE");}
#line 812 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 127 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "WHILE");}
#line 818 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 128 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "DO");}
#line 824 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 129 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "FOR");}
#line 830 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 130 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "BY");}
#line 836 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 131 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "RETURN");}
#line 842 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 132 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "IN");}
#line 848 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 133 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "BREAK");}
#line 854 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 134 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "OR");}
#line 860 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 135 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "AND");}
#line 866 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 136 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "STATIC");}
#line 872 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 137 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "NOT");}
#line 878 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 138 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "INT");}
#line 884 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 139 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "CHAR");}
#line 890 "token_parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 140 "token_parser.y" // lalr1.cc:859
    { parser::PrintOperator(context.loc.line, "BOOL");}
#line 896 "token_parser.tab.cc" // lalr1.cc:859
    break;


#line 900 "token_parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   TokenParser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   TokenParser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  TokenParser ::yypact_ninf_ = -53;

  const signed char  TokenParser ::yytable_ninf_ = -1;

  const signed char
   TokenParser ::yypact_[] =
  {
      63,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53
  };

  const unsigned char
   TokenParser ::yydefact_[] =
  {
       0,    56,    57,    58,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    39,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    40,    41,
      21,    22,    23,    24,    25,    26,    31,    32,    33,    34,
      35,    36,    37,    38,    27,    28,    29,    30,     7,     8,
       9,    10,    11,     0,     3,     4,     5,     6,     1,     2
  };

  const signed char
   TokenParser ::yypgoto_[] =
  {
     -53,   -53,   -52,   -53,   -53,   -53
  };

  const signed char
   TokenParser ::yydefgoto_[] =
  {
      -1,    53,    54,    55,    56,    57
  };

  const unsigned char
   TokenParser ::yytable_[] =
  {
      58,    59,     0,     1,     2,     3,     4,     0,     5,     0,
       6,     0,     7,     0,     8,     0,     9,     0,    10,     0,
      11,     0,    12,     0,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     1,     2,     3,     4,
       0,     5,     0,     6,     0,     7,     0,     8,     0,     9,
       0,    10,     0,    11,     0,    12,     0,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52
  };

  const signed char
   TokenParser ::yycheck_[] =
  {
       0,    53,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      10,    -1,    12,    -1,    14,    -1,    16,    -1,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     3,     4,     5,     6,
      -1,     8,    -1,    10,    -1,    12,    -1,    14,    -1,    16,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65
  };

  const unsigned char
   TokenParser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,    10,    12,    14,    16,
      18,    20,    22,    24,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,     0,    68
  };

  const unsigned char
   TokenParser ::yyr1_[] =
  {
       0,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71
  };

  const unsigned char
   TokenParser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  TokenParser ::yytname_[] =
  {
  "$end", "error", "$undefined", "TYPE_INT", "TYPE_CHAR", "TYPE_BOOL",
  "T_DECL_SEP", "','", "T_COLON", "':'", "T_LHS_BRACK", "'['",
  "T_RHS_BRACK", "']'", "T_END_STMT", "';'", "T_LHS_PAREN", "'('",
  "T_RHS_PAREN", "')'", "T_LHS_BRACE", "'{'", "T_RHS_BRACE", "'}'",
  "T_OP_ASSIGN", "'='", "\"if\"", "\"then\"", "\"else\"", "\"while\"",
  "\"do\"", "\"for\"", "\"by\"", "\"return\"", "\"in\"", "\"break\"",
  "\"or\"", "\"and\"", "\"static\"", "\"not\"", "\"--\"", "\"++\"",
  "T_OP_LES_EQ", "T_OP_LESS", "T_OP_GREAT", "T_OP_GRE_EQ", "T_OP_EQUALIVE",
  "T_OP_NOT_EQUAL", "T_OP_COMP_ASG", "T_OP_MAX", "T_OP_MIN", "T_OP_MINUS",
  "T_OP_PLUS", "T_OP_MULTI", "T_OP_DIVIDE", "T_OP_MODULO",
  "T_OP_GENERATOR", "T_OP_ADDASS", "T_OP_MINASS", "T_OP_MULASS",
  "T_OP_DIVASS", "T_STRINGCONST", "T_NUMCONST", "T_CHARCONST",
  "T_BOOLCONST", "T_IDENTIFIER", "$accept", "Start", "Program",
  "Constants", "Operators", "Keywords", YY_NULLPTR
  };


  const unsigned char
   TokenParser ::yyrline_[] =
  {
       0,    76,    76,    77,    80,    81,    82,    85,    86,    87,
      88,    89,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140
  };

  // Print the state stack on the debug stream.
  void
   TokenParser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   TokenParser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
   TokenParser ::token_number_type
   TokenParser ::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,    19,     2,     2,     7,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     9,    15,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    11,     2,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     8,    10,    12,    14,    16,    18,    20,    22,
      24,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
    };
    const unsigned int user_token_number_max_ = 310;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 3 "token_parser.y" // lalr1.cc:1167
} //  parser 
#line 1292 "token_parser.tab.cc" // lalr1.cc:1167
#line 142 "token_parser.y" // lalr1.cc:1168


void parser::TokenParser::error(const location_type &l, const std::string & error_message)
{
  std::cerr << "Error: " << error_message << " at " << l << "\n";
}
