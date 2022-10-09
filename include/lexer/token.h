#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"

#include <string_view>

namespace lexer
{
    struct Token
    {
        TokenType type {};
        std::string_view text {};
    };
} // namespace lexer

#endif
