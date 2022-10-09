#include "lexing/token.h"

#include <string_view>

namespace lexing
{
    Token::Token(TokenType type, std::string_view text)
        : m_type(type), m_text(text)
    {
    }
} // namespace lexing
