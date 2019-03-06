#include <functional>

template <typename T, typename... Args>
class CallBack {
        public:
            CallBack(std::function<T(Args...)> func) : _func(func) {};
            void execute(Args... args) const { _func(std::forward<Args>(args)...); };

        private:
            std::function<T(Args...)> _func;
};

