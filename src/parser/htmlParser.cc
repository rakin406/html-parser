#include "htmlParser.h"

#include "constants/tags.h"

#include <fstream>
#include <string>
#include <string_view>

namespace
{
    // TODO: Add indent after newline
    /**
     * @brief Add newline after closing tags.
     *
     * @param document HTML document.
     */
    void addNewlineAfterClosingTags(std::string& document)
    {
        std::size_t length { document.size() };
        // std::string_view lastTag {};
        for (std::size_t i = 0; i < length; ++i)
        {
            // Match closing tag character '>' and ensure that the letter after
            // '>' is not a newline.
            if ((document[i] == '>') && (++i < length) &&
                (document[++i] != '\n'))
            {
                document.insert(++i, "\n");
            }
        }
    }
} // namespace

namespace hp
{
    HtmlParser::HtmlParser(std::string_view str) : m_document(str) {}

    HtmlParser::HtmlParser(std::ifstream& file)
    {
        if (file.is_open())
        {
            // Copy the file content to member variable
            m_document =
                std::string { std::istreambuf_iterator<char>(file), {} };
        }
    }

    std::string_view HtmlParser::prettify()
    {
        std::string prettyDoc { m_document.data() };
        addNewlineAfterClosingTags(prettyDoc);
        return std::string_view { prettyDoc };
    }

    // std::string_view HtmlParser::decode() {}
} // namespace hp
