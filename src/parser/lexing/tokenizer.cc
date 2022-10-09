#include "lexing/tokenizer.h"

#include "lexing/token.h"
#include "lexing/tokenType.h"

#include <string_view>
#include <vector>

namespace lexing
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
        char c { advance() };

        // TODO: Finish this
        switch (c)
        {
        case '<':
            addToken(TokenType::openingTag, start);
            break;
        case '>':
            addToken(TokenType::closingTag, start);
            break;
        default:
            break;
        }
    }

    char Tokenizer::advance()
    {
        ++m_current;
        return m_source.at(m_current - 1);
    }

    void Tokenizer::addToken(TokenType type, int start)
    {
        std::string_view text { m_source.substr(start, m_current) };
        m_tokens.push_back(Token { type, text });
    }

} // namespace lexing
