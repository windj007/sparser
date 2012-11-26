#include <iostream>
#include <fstream>


#include "sparser/parser.hpp"
#include "sparser/jsoncpp.hpp"

#include <boost/lambda/lambda.hpp>
#include <jsoncpp/json/reader.h>

std::string readFile(const std::string &filename)
{
    std::ifstream str(filename.c_str());
    std::string result;
    while (str.good())
    {
        char buf = 0;
        str.get(buf);
        result += buf;
    }
    return result;
}

struct printer_t
{
public:
    printer_t(const std::string &prefix)
        : m_prefix(prefix)
    { }

    void operator() (const Json::Value &tree) const
    {
        std::cout << m_prefix << " " << tree.toStyledString() << std::endl;
    }
private:
    std::string m_prefix;
};

SP_PARSER(test_parser,
    sp::map(
        sp::optional(std::string("cls_pool"),
            sp::one_of(
                sp::match(std::string("type"), Json::Value("1"), printer_t("pool1")),
                sp::match(std::string("type"), Json::Value("2"), printer_t("pool2"))
            )
        ),
        sp::ordinary(std::string("learn"),
            sp::list(
                sp::one_of(
                    sp::match(std::string("teacher"), Json::Value("1"), printer_t("teacher1")),
                    sp::match(std::string("teacher"), Json::Value("2"), printer_t("teacher2"))
                )
            )
        ),
        sp::ordinary(std::string("storage"),
            sp::one_of(
                sp::match(std::string("type"), Json::Value("1"), printer_t("storage1")),
                sp::match(std::string("type"), Json::Value("2"), printer_t("storage2"))
            )
        )
    )
)

int main(int argc, char **argv) {
    if (argc < 2)
    {
        std::cout << argv[0] << " filename" << std::endl;
        return 1;
    }
    std::string content = readFile(argv[1]);

    Json::Value tree;
    if (!sp::parse_jsoncpp(content, tree))
    {
        std::cout << "error!" << std::endl;
        return 2;
    }

    std::cout << (test_parser(tree) ? "parsed" : "failed") << std::endl;
    return 0;
}
