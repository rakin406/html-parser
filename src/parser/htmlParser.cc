#include "htmlParser.h"

#include <fstream>
#include <string_view>

namespace hp
{
    HtmlParser::HtmlParser(std::string_view str) {}

    HtmlParser::HtmlParser(std::fstream file) {}

    std::string_view HtmlParser::decode() {}
} // namespace hp
