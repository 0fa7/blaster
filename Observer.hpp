#pragma once

#include <any>
#include <string>
#include <string_view>

using std::any;
using std::string;
using std::string_view;

class Observer
{
public:
    explicit Observer(string_view name);
    virtual ~Observer() = default;

    void notify(const any& data);

    const string& name() const { return observerName_; }

    virtual void notifyImpl(const any& data) = 0;

    string observerName_;
};

Observer::Observer(string_view name)
: observerName_{name}
{ }

void Observer::notify(const any& d)
{
    notifyImpl(d);
    return;
}
