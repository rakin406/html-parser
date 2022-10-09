#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"

#include <string_view>
#include <vector>

namespace lexer
{
    class Tokenizer
    {
    public:
        explicit Tokenizer(std::string_view source);
        std::vector<Token> scanAllTokens();

    private:
        std::string_view m_source {};
        std::vector<Token> m_tokens {};
        int m_current { 0 };
        int m_line { 1 };

        /**
         * @brief Get current char.
         *
         * @return char.
         */
        char current();

        /**
         * @brief Get char after specified index.
         *
         * @param index Position to increment.
         *
         * @return char.
         */
        char peek(int index);

        bool isAtEnd();
        void scanToken();

        void addToken(TokenType type, int start);
    };
} // namespace lexer

#endif
