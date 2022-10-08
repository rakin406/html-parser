#include "lexing/token.h"

#include <string_view>

namespace hp::lexing
{
    Token::Token(TokenType type, std::string_view lexeme, int literal, int line)
        : m_type(type), m_lexeme(lexeme), m_literal(literal), m_line(line)
    {
    }

    // TODO: Convert m_type to string
    // std::string_view Token::toString()
    // {
    //     return m_type + " " + m_lexeme + " " + m_literal;
    // }
} // namespace hp::lexing
