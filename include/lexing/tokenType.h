#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace lexing
{
    enum class TokenType
    {
        OPENING_TAG,
        ELEMENT,
        CLOSING_TAG,
        EOF
    };
}

#endif
