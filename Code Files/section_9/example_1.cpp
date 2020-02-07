struct C
{
    enum class LongEnumName
    {
        FIRST,
        SECOND,
        THIRD,
    };
};

int main()
{
    using enum C::LongEnumName;
    C::LongEnumName val = FIRST;

    switch(val)
    {
        case FIRST:
            break;
        case SECOND:
            break;
        case THIRD:
            break;
    }
}
