#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace lexer
{
    enum class TokenType
    {
        lessThan,         // <
        greaterThan,      // >
        slashGreaterThan, // />
        openingTag,       // <body>
        closingTag,       // </body>
        completeTag,      // <body />
        attribute,        // src
        equals,           // =
        text,             // "Hello"
        whitespace
    };
}

#endif
