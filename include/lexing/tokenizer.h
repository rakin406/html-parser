#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"

#include <string_view>
#include <vector>

namespace lexing
{
    class Tokenizer
    {
    public:
        explicit Tokenizer(std::string_view source);
        std::vector<Token> scanAllTokens();

    private:
        std::string_view m_source {};
        std::vector<Token> m_tokens {};
        int m_start { 0 };
        int m_current { 0 };
        int m_line { 1 };

        bool isAtEnd();
        void scanToken();
        char advance();
        void addToken(TokenType type);
    };
} // namespace lexing

#endif
