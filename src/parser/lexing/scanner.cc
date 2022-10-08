#include "lexing/scanner.h"

#include "lexing/token.h"
#include "lexing/tokenType.h"

#include <string_view>
#include <vector>

namespace hp::lexing
{
    Scanner::Scanner(std::string_view source) : m_source(source) {}

    std::vector<Token> Scanner::scanTokens()
    {
        while (!isAtEnd())
        {
            // We are at the beginning of the next lexeme
            m_start = m_current;
            scanTokens();
        }

        m_tokens.emplace_back(TokenType::EOF, "", 0, m_line);
        return m_tokens;
    }

    bool Scanner::isAtEnd()
    {
        return static_cast<std::size_t>(m_current) >= m_source.size();
    }
} // namespace hp::lexing
