#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace hp::lexing
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
