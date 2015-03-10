#include "ResourceManager.h"

#include "Shader.h"
#include "Texture.h"

namespace blasted_city {

ResourceManagerImpl::ResourceManagerImpl()
{
    u_char blackData[] = { 0, 0, 0 };

    m_textures[kBlackPixel] = TexturePtr(Texture::CreateFromData(1, 1, blackData, kU8rgb));
}

ResourceManagerImpl::~ResourceManagerImpl()
{
    Clear();
}

void ResourceManagerImpl::Clear()
{
    m_shaders.clear();
    m_textures.clear();
}

void ResourceManagerImpl::CreateShader(const std::string &id,
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

void ResourceManagerImpl::CreateTexture(const std::string &id,
                                        const std::string &imageFile)
{
    if (imageFile.rfind(".png") == imageFile.length() - 4) {
        m_textures[id] = TexturePtr(Texture::CreateFromPNGFile(imageFile));
    } else if ((imageFile.rfind(".jpg") == imageFile.length() - 4)
               || (imageFile.rfind(".jpeg") == imageFile.length() - 5)) {
        m_textures[id] = TexturePtr(Texture::CreateFromJPEGFile(imageFile));
    }
}

ShaderPtr ResourceManagerImpl::GetShader(const std::string &id) const
{
    return m_shaders.at(id);
}

TexturePtr ResourceManagerImpl::GetTexture(const std::string &id) const
{
    return m_textures.at(id);
}

} // namespace blasted_city
