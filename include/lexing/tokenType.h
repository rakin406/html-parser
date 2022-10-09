#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace lexing
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
