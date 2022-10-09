#include "parser/htmlParser.h"

#include "lexer/tokenizer.h"

#include <fstream>
#include <string>
#include <string_view>
#include <vector>

namespace parser
{
    HtmlParser::HtmlParser(std::string_view document)
    {
        lexer::Tokenizer tokenizer(document);
        m_tokens = tokenizer.scanAllTokens();
    }

    HtmlParser::HtmlParser(std::ifstream& file)
    {
        if (file.is_open())
        {
            // Copy the file content to member variable
            std::string document = { std::istreambuf_iterator<char>(file), {} };
            lexer::Tokenizer tokenizer(document);
            m_tokens = tokenizer.scanAllTokens();
        }
    }

    // std::string_view HtmlParser::decode() {}

    // void HtmlParser::PageElement::append(std::string_view tag) {}
    // void HtmlParser::PageElement::extract() {}

    // void HtmlParser::Tag::decompose() {}
    //
    // std::string_view HtmlParser::Tag::findChild() {}
    //
    // std::vector<std::string_view> HtmlParser::Tag::findChildren() {}
    //
    // std::string_view HtmlParser::Tag::get() {}
    //
    // std::vector<std::string_view> HtmlParser::Tag::getText() {}
    //
    // bool HtmlParser::Tag::hasKey() {}
    //
    // bool HtmlParser::Tag::isEmptyElement() {}

} // namespace parser
