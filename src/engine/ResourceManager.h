#pragma once

#include "../global.h"

#include "../base/Singleton.h"

#include <map>

namespace blasted_city {

class Shader;
using ShaderPtr = std::shared_ptr<Shader>;

class Texture;
using TexturePtr = std::shared_ptr<Texture>;

constexpr auto kBlackPixel = "blackPixel";

class ResourceManagerImpl
{
public:
    ~ResourceManagerImpl();

    void                    Clear();
    void                    CreateShader(const std::string &id,
                                         const std::string &vertexShaderSourceFile,
                                         const std::string &fragmentShaderSourceFile,
                                         const std::string &geometryShaderSourceFile);
    void                    CreateTexture(const std::string &id,
                                          const std::string &imageFile);
    ShaderPtr               GetShader(const std::string &id) const;
    TexturePtr              GetTexture(const std::string &id) const;

private:
    friend class Singleton<ResourceManagerImpl>;

    ResourceManagerImpl();

    std::map<std::string, ShaderPtr>  m_shaders;
    std::map<std::string, TexturePtr> m_textures;
};

using ResourceManager = Singleton<ResourceManagerImpl>;

} // namespace blasted_city
