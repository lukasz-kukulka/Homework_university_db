
class Command {
public:
    virtual ~Command() = default;
    virtual void operator()() = 0;
};