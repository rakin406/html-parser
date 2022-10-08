#ifndef PAGE_ELEMENT_H
#define PAGE_ELEMENT_H

#include <string_view>

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

#endif
