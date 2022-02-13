#pragma once

#include <ranges>
#include <algorithm>
#include <any>
#include <string>
#include <format>
#include <set>
#include <memory>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "Observer.hpp"

using std::string;
using std::vector;
using std::set;
using std::unique_ptr;
using std::shared_ptr;
using std::any;
using std::unordered_map;

namespace views = std::views;
namespace ranges = std::ranges;

class Publisher
{
    using ObserversList = unordered_map<string, unique_ptr<Observer>>;
    using Events = unordered_map<string, ObserversList>;

public:
    Publisher() = default;

    void attach(const string& eventName, unique_ptr<Observer> observer);
    unique_ptr<Observer> detach(const string& eventName, const string& observerName);

    set<string> listEvents() const;
    set<string> listEventObservers(const string& eventName) const;
    void raise(const string& eventName) const;
    void raise(const string& eventName, any data) const;

    void registerEvent(const string& eventName);
    void registerEvents(const vector<string>& eventNames);

private:
    Events::const_iterator findCheckedEvent(const string& eventName) const;
    Events::iterator findCheckedEvent(const string& eventName);

    Events events_;
};

Publisher::Events::const_iterator Publisher::findCheckedEvent(const string& eventName) const
{
    auto ev = events_.find(eventName);
    if( ev == events_.end() )
    {
        
    }

    return ev;
}

Publisher::Events::iterator Publisher::findCheckedEvent(const string &eventName)
{
    auto ev = events_.find(eventName);
    if( ev == events_.end() )
    {
        
    }

    return ev;
}

void Publisher::attach(const string& eventName, unique_ptr<Observer> observer)
{
    auto& obsList = findCheckedEvent(eventName)->second;
    obsList.insert( std::pair(observer->name(), std::move(observer)) );

    return;
}

unique_ptr<Observer> Publisher::detach(const string& eventName, const string& observer)
{
    auto& obsList = findCheckedEvent(eventName)->second;

    auto obs = obsList.find(observer);

    auto tmp = std::move(obs->second);
    obsList.erase(obs);

    return tmp;
}


void Publisher::raise(const string& eventName) const
{
    raise(eventName, any{});
}

void Publisher::raise(const string& eventName, const std::any d) const
{
    const auto& obsList = findCheckedEvent(eventName)->second;
    ranges::for_each( views::values(obsList), [d](const auto& v){ v->notify(d);} );
    return;
}

void Publisher::registerEvent(const string& eventName)
{
    events_[eventName] = ObserversList{};

    return;
}

void Publisher::registerEvents(const vector<string>& eventNames)
{
    ranges::for_each(eventNames, [this](const auto& i){registerEvent(i);});

    return;
}

set<string> Publisher::listEvents() const
{
    set<string> tmp;
    ranges::for_each(events_, [&tmp](const auto& i){tmp.insert(i.first);});

    return tmp;
}

set<string> Publisher::listEventObservers(const string& eventName) const
{
    auto ev = findCheckedEvent(eventName);

    set<string> tmp;

    ranges::for_each( ev->second | views::keys, [&tmp](const auto& k){tmp.insert(k);} );

    return tmp;
}