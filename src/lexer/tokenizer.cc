#include "lexer/tokenizer.h"

#include "lexer/token.h"
#include "lexer/tokenType.h"

#include <cctype>
#include <string_view>
#include <vector>

namespace lexer
{
    Tokenizer::Tokenizer(std::string_view source) : m_source(source) {}

    std::vector<Token> Tokenizer::scanAllTokens()
    {
        while (!isAtEnd())
        {
            // We are at the beginning of the next lexeme
            scanToken();
        }
        return m_tokens;
    }

    bool Tokenizer::isAtEnd()
    {
        return static_cast<std::size_t>(m_current) >= m_source.size();
    }

    void Tokenizer::scanToken()
    {
        int start { m_current };
        ++m_current;
        char c { m_source[m_current - 1] };

        if (std::isspace(c) != 0)
        {
            addToken(TokenType::whitespace, start);
        }

        // TODO: Finish this
        switch (c)
        {
        case '<':
            addToken(TokenType::lessThan, start);
            break;
        case '>':
            addToken(TokenType::greaterThan, start);
            break;
        case '/':
            if (peek(1) == '>')
            {
                addToken(TokenType::slashGreaterThan, start);
            }
            break;
        case '=':
            addToken(TokenType::equals, start);
            break;
        default:
            break;
        }
    }

    void Tokenizer::addToken(TokenType type, int start)
    {
        std::string_view text { m_source.substr(start, m_current) };
        m_tokens.push_back(Token { type, text });
    }

    char Tokenizer::current() { return m_source[m_current]; }

    char Tokenizer::peek(int index) { return m_source[m_current + index]; }

} // namespace lexer
