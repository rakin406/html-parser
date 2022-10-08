#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"

#include <string_view>

namespace lexing
{
    class Token
    {
    public:
        Token(TokenType type, std::string_view name);

    private:
        TokenType m_type {};
        std::string_view m_name {};
    };
} // namespace lexing

#endif
