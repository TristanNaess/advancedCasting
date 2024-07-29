#include <string>

class container
{
    private:
        class accessor
        {
            private:
                accessor(container* parent);
            public:

                accessor() = delete;
                accessor(const accessor&) = delete;
                accessor(accessor&&) = delete;
                accessor& operator=(const accessor&) = delete;
                accessor& operator=(accessor&&) = delete;

                accessor& operator=(const std::string& s);
                accessor& operator=(const char* c);
                operator std::string() const;

                accessor& operator=(long double d);
                accessor& operator=(double d);
                accessor& operator=(float d);
                operator long double() const;
                operator double() const;
                operator float() const;

                accessor& operator=(long long i);
                accessor& operator=(long i);
                accessor& operator=(int i);
                operator long long() const;
                operator long() const;
                operator int() const;
                // need unsigned versions

                accessor& operator=(bool b);
                operator bool() const;

            private:
                container* parent;
                friend class container;
        };

    public:
        container(const std::string& data);

        //const accessor get() const; // this requires a const_accessor type where parent is const
        accessor get();

    private:
        std::string data;

        friend class accessor;
};
