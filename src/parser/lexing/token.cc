#include "lexing/token.h"

#include <string_view>

namespace lexing
{
    Token::Token(TokenType type, std::string_view name)
        : m_type(type), m_name(name)
    {
    }
} // namespace lexing
