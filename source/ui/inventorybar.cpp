#include "inventorybar.h"
#include "render/mesh.h"
#include "world/block/blockmanager.h"

InventoryBar &InventoryBar::instance()
{
    static InventoryBar i;
    return i;
}

void InventoryBar::scrollCallback(GLFWwindow *, double, double yoffset)
{
    InventoryBar::instance().setIndicator(yoffset);
}

void InventoryBar::setIndicator(double yoffset)
{
    _indicator += INVENTORY_NUM - yoffset;
    _indicator %= INVENTORY_NUM;

    makeMesh();
}

void InventoryBar::makeMesh()
{
    makeMesh2D();
    makeMesh3D();
}

void InventoryBar::makeMesh2D()
{
    static constexpr int lb = WINDOW_WIDTH / 2 - INVENTORY_NUM * INVENTORY_BLOCK_SIZE / 2;
    static constexpr int rb = lb + INVENTORY_NUM * INVENTORY_BLOCK_SIZE;
    static constexpr int CLIPED_SIZE = INVENTORY_BLOCK_SIZE - INVENTORY_BORDER_SIZE;

    ColorMesh mesh;

    auto &vps = mesh.vertexPositions;
    auto &vcs = mesh.vertexColors;
    auto &ids = mesh.indices;

    GLuint indexCount = 0;

    // make background
    vps.insert(vps.end(), {
                   lb, INVENTORY_BLOCK_SIZE,
                   lb, 0,
                   rb, 0,
                   rb, INVENTORY_BLOCK_SIZE,
               });

    vcs.insert(vcs.end(), {
                   0, 0, 0, 0.4f,
                   0, 0, 0, 0.4f,
                   0, 0, 0, 0.4f,
                   0, 0, 0, 0.4f,
               });

    ids.insert(ids.end(), {
                   indexCount, indexCount + 1, indexCount + 2,
                   indexCount + 2, indexCount + 3, indexCount,
               });

    indexCount += 4;

    auto vps_insert = [&](unsigned i, GLfloat EXPAND_SIZE) {
        const GLfloat base = lb + i * INVENTORY_BLOCK_SIZE;

        vps.insert(vps.end(), {
                       // up
                       base - EXPAND_SIZE, INVENTORY_BLOCK_SIZE + EXPAND_SIZE,
                       base + INVENTORY_BORDER_SIZE, CLIPED_SIZE,
                       base + CLIPED_SIZE, CLIPED_SIZE,
                       base + EXPAND_SIZE + INVENTORY_BLOCK_SIZE, INVENTORY_BLOCK_SIZE + EXPAND_SIZE,

                       // left
                       base - EXPAND_SIZE, INVENTORY_BLOCK_SIZE + EXPAND_SIZE,
                       base - EXPAND_SIZE, 0 - EXPAND_SIZE,
                       base + INVENTORY_BORDER_SIZE, INVENTORY_BORDER_SIZE,
                       base + INVENTORY_BORDER_SIZE, CLIPED_SIZE,

                       // bottom
                       base + INVENTORY_BORDER_SIZE, INVENTORY_BORDER_SIZE,
                       base - EXPAND_SIZE, 0 - EXPAND_SIZE,
                       base + EXPAND_SIZE + INVENTORY_BLOCK_SIZE, 0 - EXPAND_SIZE,
                       base + CLIPED_SIZE, INVENTORY_BORDER_SIZE,

                       // right
                       base + CLIPED_SIZE, CLIPED_SIZE,
                       base + CLIPED_SIZE, INVENTORY_BORDER_SIZE,
                       base + EXPAND_SIZE + INVENTORY_BLOCK_SIZE, 0 - EXPAND_SIZE,
                       base + EXPAND_SIZE + INVENTORY_BLOCK_SIZE, INVENTORY_BLOCK_SIZE + EXPAND_SIZE,
                   });
    };

    auto vcs_insert = [&](const std::vector<GLfloat> &v, const std::vector<GLfloat> &h) {
        for (int i = 0; i < 4; ++i) {
            if (i % 2 == 0) {
                // vertical
                vcs.insert(vcs.end(), v.begin(), v.end());
            } else {
                // horizontal
                vcs.insert(vcs.end(), h.begin(), h.end());
            }
        }
    };

    auto ids_insert = [&]() {
        for (int i = 0; i < 4; ++i) {
            ids.insert(ids.end(), {
                           indexCount, indexCount + 1, indexCount + 2,
                           indexCount + 2, indexCount + 3, indexCount,
                       });

            indexCount += 4;
        }
    };

    // make no indicator
    for (unsigned i = 0; i < INVENTORY_NUM; ++i) {
        if (i != _indicator) {
            vps_insert(i, 0);
            vcs_insert({
                           0.6f, 0.6f, 0.6f, 1,
                           0.35f, 0.35f, 0.35f, 1,
                           0.35f, 0.35f, 0.35f, 1,
                           0.6f, 0.6f, 0.6f, 1,
                       }, {
                           0.6f, 0.6f, 0.6f, 1,
                           0.6f, 0.6f, 0.6f, 1,
                           0.35f, 0.35f, 0.35f, 1,
                           0.35f, 0.35f, 0.35f, 1,
                       });
            ids_insert();
        }
    }

    // make indicator
    vps_insert(_indicator, 2);
    vcs_insert({
                   0.85f, 0.95f, 0.85f, 1,
                   0.35f, 0.45f, 0.35f, 1,
                   0.35f, 0.45f, 0.35f, 1,
                   0.85f, 0.95f, 0.85f, 1,
               }, {
                   0.85f, 0.95f, 0.85f, 1,
                   0.85f, 0.95f, 0.85f, 1,
                   0.35f, 0.45f, 0.35f, 1,
                   0.35f, 0.45f, 0.35f, 1,
               });
    ids_insert();

    _model2D.addData(mesh);
}

void InventoryBar::makeMesh3D()
{
    static constexpr int lb = WINDOW_WIDTH / 2 - INVENTORY_NUM * INVENTORY_BLOCK_SIZE / 2;

    auto &atlas = BlockManager::instance().textureAtlas();

    std::vector<GLfloat> vertexPositions;
    std::vector<GLfloat> textureCoords;
    std::vector<GLuint>  indices;

    for (unsigned i = 0; i < _items.size(); ++i) {
        if (_items[i] == BlockId::AIR) {
            continue;
        }

        const GLfloat base = lb + i * INVENTORY_BLOCK_SIZE;

        std::vector<GLfloat> vp = CUBE_VERTEX_POSITION;

        for (unsigned j = 0; j < vp.size(); j += 3) {
            vp[j+0] = vp[j+0] * INVENTORY_ITEM_SIZE + base + INVENTORY_BLOCK_SIZE / 2;
            vp[j+1] = vp[j+1] * INVENTORY_ITEM_SIZE + INVENTORY_BLOCK_SIZE / 2;
            vp[j+2] = 0;
        }

        auto &data = BlockManager::instance().getData(_items[i]);

        auto top    = atlas.getTexture(data.texTopCoord);
        auto side   = atlas.getTexture(data.texSideCoord);
        auto bottom = atlas.getTexture(data.texBottomCoord);

        std::vector<GLfloat> tc;

        tc.insert(tc.end(), side.begin(),   side.end());
        tc.insert(tc.end(), side.begin(),   side.end());
        tc.insert(tc.end(), side.begin(),   side.end());
        tc.insert(tc.end(), side.begin(),   side.end());
        tc.insert(tc.end(), top.begin(),    top.end());
        tc.insert(tc.end(), bottom.begin(), bottom.end());

        std::vector<GLuint> id = CUBE_INDICES;

        std::transform(id.begin(), id.end(), id.begin(), [i](GLuint u) { return u + i * 24; });

        vertexPositions.insert(vertexPositions.end(), vp.begin(), vp.end());
        textureCoords.insert(textureCoords.end(), tc.begin(), tc.end());
        indices.insert(indices.end(), id.begin(), id.end());
    }

    _model3D.addData(TextureMesh(vertexPositions, textureCoords, indices));
}

InventoryBar::InventoryBar()
{
    for (unsigned i = 1; i < static_cast<unsigned>(BlockId::NUM_TYPES) && i - 1 < _items.size(); ++i) {
        _items[i-1] = static_cast<BlockId>(i);
    }

    makeMesh();
}
