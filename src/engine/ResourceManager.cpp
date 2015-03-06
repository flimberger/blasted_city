#include "ResourceManager.h"

#include "Shader.h"
#include "Texture.h"

namespace blasted_city {

ResourceManager::ResourceManager() = default;

ResourceManager::~ResourceManager()
{
    Clear();
}

void ResourceManager::Clear()
{
    m_shaders.clear();
    m_textures.clear();
}

void ResourceManager::CreateShader(const std::string &id,
                                   const std::string &vertexShaderSourceFile,
                                   const std::string &fragmentShaderSourceFile,
                                   const std::string &geometryShaderSourceFile)
{
    m_shaders[id] = ShaderPtr(Shader::Create(ReadTextFile(vertexShaderSourceFile),
                                             ReadTextFile(fragmentShaderSourceFile),
                                             geometryShaderSourceFile.empty()
                                             ? std::string()
                                             : ReadTextFile(geometryShaderSourceFile)));
}

void ResourceManager::CreateTexture(const std::string &id,
                                    const std::string &imageFile)
{
    if (imageFile.rfind(".png") == imageFile.length() - 4) {
        m_textures[id] = TexturePtr(Texture::CreateFromPNGFile(imageFile));
    } else if ((imageFile.rfind(".jpg") == imageFile.length() - 4)
               || (imageFile.rfind(".jpeg") == imageFile.length() - 5)) {
        m_textures[id] = TexturePtr(Texture::CreateFromJPEGFile(imageFile));
    }
}

ResourceManager &ResourceManager::GetInstance()
{
    static ResourceManager s_instance;

    return s_instance;
}

ShaderPtr ResourceManager::GetShader(const std::string &id) const
{
    return m_shaders.at(id);
}

TexturePtr ResourceManager::GetTexture(const std::string &id) const
{
    return m_textures.at(id);
}

} // namespace blasted_city
