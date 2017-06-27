

#ifndef MN_POSTMAN_POSTMAN_H_
#define MN_POSTMAN_POSTMAN_H_

#include <functional>

namespace mn {
    namespace HearYeHearYe {

        template<typename T>
        class Event {


        public:
            void AddListener(std::function<T> listener) {
                listeners.push_back(listener);
            };

            template <class ...Arg>
            void Fire(Arg... parameters) {
                for(auto listener : listeners) {
                    listener(std::forward<Arg>(parameters)...);
                }
            }

        private:
            std::vector<std::function<T>> listeners;

        };

    }
}

#endif