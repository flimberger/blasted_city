#ifndef BLASTED_CITY_ENGINE_WINDOW_H_
#define BLASTED_CITY_ENGINE_WINDOW_H_

#include "../global.h"

#include "../base/Singleton.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <array>
#include <tuple>

namespace blasted_city {

enum KeySymbol {
    // numbers
    kKey0,
    kKey1,
    kKey2,
    kKey3,
    kKey4,
    kKey5,
    kKey6,
    kKey7,
    kKey8,
    kKey9,
    // letters
    kKeyA,
    kKeyB,
    kKeyC,
    kKeyD,
    kKeyE,
    kKeyF,
    kKeyG,
    kKeyH,
    kKeyI,
    kKeyJ,
    kKeyK,
    kKeyL,
    kKeyM,
    kKeyN,
    kKeyO,
    kKeyP,
    kKeyQ,
    kKeyR,
    kKeyS,
    kKeyT,
    kKeyU,
    kKeyV,
    kKeyW,
    kKeyX,
    kKeyY,
    kKeyZ,
    // stuff
    kKeyEnter,
    kKeyEscape,
    kKeyLeftAlt,
    kKeyLeftControl,
    kKeyLeftShift,
    kKeyRightAlt,
    kKeyRightControl,
    kKeyRightShift,
    kKeySpace,
    // arrows
    kKeyUp,
    kKeyLeft,
    kKeyDown,
    kKeyRight,
    // Number of keys
    kNumberOfKeySymbols
};

enum KeyStateAttrib {
    kKeyPressed,
    kKeyFlankDown,
    kKeyFlankUp
};

using KeyState = std::tuple<bool, bool, bool>;

class WindowImpl
{
public:
    WindowImpl(const WindowImpl &) = delete;
    ~WindowImpl();

    size_t          GetHeight() const;
    size_t          GetWidth() const;
    bool            IsOpen() const;
    const KeyState *GetKeyStates() const;
    void            BeginFrame();
    void            EndFrame() const;
    void            Shutdown();

private:
    friend class Singleton<WindowImpl>;

    WindowImpl();

    void ProcessKeys();

    GLFWwindow                               *m_window;
    std::array<KeyState, kNumberOfKeySymbols> m_keyPressTable;
};

using Window = Singleton<WindowImpl>;

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_WINDOW_H_
