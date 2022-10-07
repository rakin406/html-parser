#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <fstream>
#include <string_view>
#include <vector>

namespace hp
{
    /**
     * @brief This class defines the basic interface called by the html parser.
     */
    class HtmlParser
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

        /**
         * @brief Contains the navigational information for some part of the
         * page (either a tag or a piece of text)
         */
        class PageElement
        {
        public:
            /**
             * @brief Appends the given tag to the contents of this tag.
             *
             * @param tag Tag string.
             */
            void append(std::string_view tag);

            /**
             * @brief Destructively rips this element out of the tree.
             */
            void extract();

            // void fetchNextSiblings();
            // void fetchParents();
            // void fetchPrevious();
            // void fetchPreviousSiblings();
            // void findAllNext();
            // void findAllPrevious();
            // void findNext();
            // void findNextSibling();
            // void findNextSiblings();
            // void findParent();
            // void findParents();
            // void findPrevious();
            // void findPreviousSibling();
            // void findPreviousSiblings();

        private:
        };

        /**
         * @brief Represents a found HTML tag with its attributes and contents.
         */
        class Tag
        {
        public:
            /**
             * @brief Destroys the contents of this tree.
             */
            void decompose();

            /**
             * @brief Return only the first child of this Tag matching the
             given
             * criteria.
             *
             * @return string.
             */
            std::string_view findChild();

            /**
             * @brief Extracts a list of Tag objects that match the given
             * criteria. You can specify the name of the Tag and any
             attributes
             * you want the Tag to have.
             *
             * @return a vector of tags.
             */
            std::vector<std::string_view> findChildren();

            /**
             * @brief Returns the value of the ‘key’ attribute for the tag,
             or
             * the value given for ‘default’ if it doesn’t have that
             attribute.
             *
             * @return value.
             */
            std::string_view get();

            /**
             * @brief Get all child strings, concatenated using the given
             * separator.
             *
             * @return a vector of strings.
             */
            std::vector<std::string_view> getText();

            /**
             * @brief Return true if element has the given key.
             *
             * @return boolean.
             */
            bool hasKey();

            /**
             * @brief Return true if tag is an empty-element tag.
             *
             * @return boolean.
             */
            bool isEmptyElement();

        private:
        };
    };
} // namespace hp

#endif
