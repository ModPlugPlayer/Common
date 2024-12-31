#include "FileUtil.hpp"
#include <boost/url.hpp>
#include <boost/url/url_view.hpp>
#include <boost/system.hpp>
#include <boost/filesystem.hpp>

std::filesystem::path FileUtil::fileURI2FilePath(const std::string &fileURI) {
    boost::core::string_view s = fileURI;
    boost::system::result<boost::url_view> r = boost::urls::parse_uri(s);
    boost::url_view u = r.value();
    return u.path();
}

std::string FileUtil::filePath2FileURI(const std::filesystem::path &filePath) {
    std::filesystem::path absPath = std::filesystem::absolute(filePath);
    std::string pathStr = absPath.string();
    boost::urls::url url;

    url.set_path(pathStr);
    url.set_scheme("file");
    //return url.buffer();
    return "file://" + (std::string) url.encoded_path();
}
