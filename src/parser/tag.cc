#include "htmlParser.h"

#include <string_view>
#include <vector>

namespace hp
{
    void HtmlParser::Tag::decompose() {}

    std::string_view HtmlParser::Tag::findChild() {}

    std::vector<std::string_view> HtmlParser::Tag::findChildren() {}

    std::string_view HtmlParser::Tag::get() {}

    std::vector<std::string_view> HtmlParser::Tag::getText() {}

    bool HtmlParser::Tag::hasKey() {}

    bool HtmlParser::Tag::isEmptyElement() {}
} // namespace hp
