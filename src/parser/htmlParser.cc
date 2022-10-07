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

    // TODO: Add newline to string after every '>' character
    // std::string_view HtmlParser::prettify() {
    //     std::string s = "scott>=tiger";
    //     std::string delimiter = ">=";
    //     std::string token = s.substr(0, s.find(delimiter)); // token is
    //     "scott"
    // }

    // std::string_view HtmlParser::decode() {}
} // namespace hp
