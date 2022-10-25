#ifndef TAG_H
#define TAG_H

#include <string_view>
#include <vector>

namespace ast
{
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
         * @brief Return only the first child of this Tag matching the given
         * criteria.
         *
         * @return string.
         */
        std::string_view findChild();

        /**
         * @brief Extracts a list of Tag objects that match the given
         * criteria. You can specify the name of the Tag and any attributes
         * you want the Tag to have.
         *
         * @return a vector of tags.
         */
        std::vector<std::string_view> findChildren();

        /**
         * @brief Returns the value of the ‘key’ attribute for the tag,
         * or the value given for ‘default’ if it doesn’t have that
         * attribute.
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
} // namespace ast

#endif
