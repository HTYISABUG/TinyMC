#ifndef VECTORXZ_H
#define VECTORXZ_H

#include <boost/functional/hash.hpp>

template <class T>
struct _VectorXZ
{
    T x, z;

    bool operator==(const _VectorXZ<T> &other)
    {
        return x == other.x && z == other.z;
    }
};

template <class T>
bool operator==(const _VectorXZ<T> &left, const _VectorXZ<T> &right)
{
    return left.x == right.x && left.z == right.z;
}

namespace std {
template <class T>
struct hash<_VectorXZ<T>>
{
    size_t operator()(const _VectorXZ<T> &vec) const
    {
        size_t seed = 0;
        boost::hash_combine(seed, vec.x);
        boost::hash_combine(seed, vec.z);
        return seed;
    }
};
}

using VectorXZ  = _VectorXZ<float>;
using VectorXZi = _VectorXZ<int>;

#endif // VECTORXZ_H
