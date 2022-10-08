#include "lexing/scanner.h"

#include "lexing/token.h"
#include "lexing/tokenType.h"

#include <string_view>
#include <vector>

namespace hp::lexing
{
    Scanner::Scanner(std::string_view source) : m_source(source) {}

    std::vector<Token> Scanner::scanAllTokens()
    {
        while (!isAtEnd())
        {
            // We are at the beginning of the next lexeme
            m_start = m_current;
            scanToken();
        }

        m_tokens.emplace_back(TokenType::EOF, "", 0, m_line);
        return m_tokens;
    }

    bool Scanner::isAtEnd()
    {
        return static_cast<std::size_t>(m_current) >= m_source.size();
    }

    void Scanner::scanToken()
    {
        char c { advance() };
        // TODO: Finish this
        switch (c)
        {
        case '<':
            addToken(TokenType::OPENING_TAG);
            break;
        case '>':
            addToken(TokenType::CLOSING_TAG);
            break;
        default:
            break;
        }
    }

    char Scanner::advance()
    {
        ++m_current;
        return m_source.at(m_current - 1);
    }

    void Scanner::addToken(TokenType type) { addToken(type, 0); }

    void Scanner::addToken(TokenType type, int literal)
    {
        std::string_view text { m_source.substr(m_start, m_current) };
        m_tokens.emplace_back(type, text, literal, m_line);
    }
} // namespace hp::lexing
