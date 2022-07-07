//
// Created by dalek on 07-07-2022.
//

#include <iostream>
#include <type_traits>

namespace cppstudy {

    namespace deep_copy_example {

        // To enable the conversion of 'enum class' values to integer.
        template <typename E>
        constexpr auto to_underlying(E e) noexcept
        {
            return static_cast<std::underlying_type_t<E>>(e);
        }

        // On 'enum class' versus 'enum':
        // https://stackoverflow.com/a/18335862/1708550
        
        // 'enum class' - introduced in C++11: enumerator names are local to the enum and their
        // values do not implicitly convert to other types (like another enum or int).

        // 'enum' - enumerator names are in the same scope as the enum and their values implicitly
        // convert to integers and other types
        enum class month : int {
            jan = 1, feb = 2, mar = 3, apr = 4,
            may = 5, jun = 6, jul = 7, aug = 8,
            sep = 9, oct = 10, nov = 11, dec = 12
        };

        std::ostream& operator << (std::ostream &os, const month &month_val) {
            //return (os << static_cast<int>(month));
            int to_int = to_underlying(month_val);
            return (os << to_int);
        }

        struct date {
          int yyyy;
          month mm;
          int dd;
        };

        std::ostream& operator << (std::ostream &os, const date &d) {
            return (os << "Name: " << d.yyyy << "-" << d.mm << "-" << d.dd  << "\n");
        }
    }
}

int main () {
    cppstudy::deep_copy_example::date a {2020, cppstudy::deep_copy_example::month::mar, 7};
    cppstudy::deep_copy_example::date b = a;  // deep copy of a
    b.dd = 22;   // change b

    std::cout << "> Start date:\t" << a << "\n";
    std::cout << "> Copied date:\t" << b << "\n";

    return 0;
}