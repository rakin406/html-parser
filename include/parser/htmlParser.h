#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include "lexer/token.h"
#include "pageElement.h"
#include "tag.h"

#include <fstream>
#include <string_view>
#include <vector>

namespace parser
{
    /**
     * @brief This class defines the basic interface called by the html parser.
     */
    class HtmlParser : public PageElement, public Tag
    {
    public:
        explicit HtmlParser(std::string_view document);
        explicit HtmlParser(std::ifstream& file);

        /**
         * @brief Returns unicode encoding of the document.
         *
         * @return unicode string.
         */
        std::string_view decode();

    private:
        std::vector<lexer::Token> m_tokens {}; // HTML tokens
    };

} // namespace parser

#endif
