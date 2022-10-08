#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace lexing
{
    enum class TokenType
    {
        openingTag,  // Example: <body>
        closingTag,  // Example: </body>
        completeTag, // Example: <body />
        text,        // Example: "Hello"
        attribute    // Example: src=""
    };
}

#endif
