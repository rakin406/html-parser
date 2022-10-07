#include "htmlParser.h"

#include <fstream>
#include <string_view>

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

    std::string_view HtmlParser::decode() {}
} // namespace hp
