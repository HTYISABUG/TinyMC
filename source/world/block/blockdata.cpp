#include "blockdata.h"

#include <fstream>
#include <boost/filesystem.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

BlockData::BlockData(const std::string &file)
{
    using namespace std;

    static const auto prefix = boost::filesystem::path("assets/models/block");

    auto path = (prefix / file).string();

    ifstream ifs(path);

    if (!ifs.is_open()) {
        throw runtime_error("Unable to open file: " + path);
    }

    json data;

    ifs >> data;

    auto textures = data["textures"];

    if (textures.find("all") != textures.end()) {
        texTopCoord = {textures["all"][0], textures["all"][1]};
        texBottomCoord = texSideCoord = texTopCoord;
    } else {
        texTopCoord    = {textures["top"][0],    textures["top"][1]};
        texSideCoord   = {textures["side"][0],   textures["side"][1]};
        texBottomCoord = {textures["bottom"][0], textures["bottom"][1]};
    }
}
