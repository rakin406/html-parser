#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace lexer
{
    enum class TokenType
    {
        lessThan,         // <
        greaterThan,      // >
        slashGreaterThan, // />
        equals,           // =
        ident,            // Example: body
        stringLiteral,    // Example: "www.google.com"
        whitespace,
        endOfFile
    };
}

#endif
