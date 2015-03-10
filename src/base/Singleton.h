#pragma once

namespace blasted_city {

template<typename T>
class Singleton
{
public:
    ~Singleton() = default;

    static T &GetInstance();

private:
    Singleton() = default;
};

template<typename T>
T &Singleton<T>::GetInstance()
{
    static T s_instance;

    return s_instance;
}

} // namespace blasted_city
