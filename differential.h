#ifndef PARACEFAS_DIFFERENTIAL_H
#define PARACEFAS_DIFFERENTIAL_H

#include <utility>
#include <math.h>


namespace paracefas {
template<typename Function>
auto derivative_(Function f, double x) {
    static const double h = 1.0E-5;
    return (f(x + h) - f(x)) / h;
}

template<typename Function>
auto derivative(Function f) {
    return [&f](double x) { derivative_(f, x); };
}

template<typename Function, typename T, size_t... I>
auto call_(Function f, T* args, std::index_sequence<I...>) {
    return f(args[I]...);
}

template<typename Function, typename T, size_t N>
auto call(Function f, T(&args)[N]) {
    return call_(f,args,std::make_index_sequence<N>{});
}

template<typename Function, typename... Args>
auto derivative_(Function f, size_t d, Args... v) {
    static const double h = 1.0E-5;
    double args[sizeof...(Args)] = {static_cast<double>(v)...};
    args[d] += h;
    return (call(f,args) - f(v...)) / h;    
}

template<typename Function>
auto derivative(Function f, size_t d) {
    return [=] (auto... x) {
        return derivative_(f, d, x...);
    };
}
} // end namespace

#endif