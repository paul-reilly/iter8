#include <type_traits>
#include <optional>
#include <functional>

namespace iter8 
{
    template <class, class = void> struct has_iterators : std::false_type {};
    template <class T> struct has_iterators<T, std::void_t<typename T::iterator>> : std::true_type {};

    template<typename Container>
    struct Iter 
    {
        using Containee = typename std::remove_reference_t<decltype(std::declval<Container>().front())>;

        Iter(Container& c) : _begin{ c.begin() }, _end{ c.end() }, _it{ c.begin() }
        {
            static_assert(has_iterators<Container>{}, "Iter requires a container with iterators.");
        }
        auto next() 
          -> std::optional<std::reference_wrapper<Containee>>
        {
            if (_it != _end)
                return *(_it++);
            else
                _it = _begin;
            return {};
        }
        auto reset()
        {
            _it = _begin;
        }

    private:
        typename Container::iterator _begin;
        typename Container::iterator _end;
        typename Container::iterator _it;
    };
}
