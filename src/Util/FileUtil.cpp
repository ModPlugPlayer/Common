/*
FileUtil class definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

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
