#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"

#include <string_view>

namespace hp::lexing
{
    class Token
    {
    public:
        Token(TokenType type, std::string_view lexeme, int* literal, int line);
        std::string_view toString();

    private:
        TokenType m_type {};
        std::string_view m_lexeme {};
        int* const m_literal {};
        int m_line {};
    };
} // namespace hp::lexing

#endif
