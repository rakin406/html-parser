#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include "pageElement.h"
#include "tag.h"

#include <fstream>
#include <string_view>

namespace hp
{
    /**
     * @brief This class defines the basic interface called by the html parser.
     */
    class HtmlParser : public PageElement, public Tag
    {
    public:
        explicit HtmlParser(std::string_view str);
        explicit HtmlParser(std::ifstream& file);

        /**
         * @brief Returns unicode encoding of the document.
         *
         * @return unicode string.
         */
        std::string_view decode();

    private:
        std::string_view m_document {}; // HTML document
    };

} // namespace hp

#endif
