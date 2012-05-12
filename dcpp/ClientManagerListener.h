/*
 * Copyright (C) 2001-2012 Jacek Sieka, arnetheduck on gmail point com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef DCPLUSPLUS_DCPP_CLIENT_MANAGER_LISTENER_H
#define DCPLUSPLUS_DCPP_CLIENT_MANAGER_LISTENER_H

#include "forward.h"
#include "noexcept.h"
#include <string>

namespace dcpp {
    
using std::string;

class ClientManagerListener {
public:
    virtual ~ClientManagerListener() { }
    template<int I> struct X { enum { TYPE = I }; };

    typedef X<0> UserConnected;
    typedef X<1> UserUpdated;
    typedef X<2> UserDisconnected;
    typedef X<3> IncomingSearch;
    typedef X<4> ClientConnected;
    typedef X<5> ClientUpdated;
    typedef X<6> ClientDisconnected;

    /** User online in at least one hub */
    virtual void on(UserConnected, const UserPtr&) noexcept { }
    virtual void on(UserUpdated, const OnlineUser&) noexcept { }
    /** User offline in all hubs */
    virtual void on(UserDisconnected, const UserPtr&) noexcept { }
    virtual void on(IncomingSearch, const string&) noexcept { }
    virtual void on(ClientConnected, Client*) noexcept { }
    virtual void on(ClientUpdated, Client*) noexcept { }
    virtual void on(ClientDisconnected, Client*) noexcept { }
};

} // namespace dcpp

#endif // DCPLUSPLUS_DCPP_CLIENT_MANAGER_LISTENER_H
