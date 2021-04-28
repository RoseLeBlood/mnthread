/*
*This file is part of the Mini Thread Library (https://github.com/RoseLeBlood/MiniThread ).
*Copyright (c) 2021 Amber-Sophia Schroeck
*
*The Mini Thread Library is free software; you can redistribute it and/or modify
*it under the terms of the GNU Lesser General Public License as published by
*the Free Software Foundation, version 3, or (at your option) any later version.

*The Mini Thread Library is distributed in the hope that it will be useful, but
*WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*General Public License for more details.
*
*You should have received a copy of the GNU Lesser General Public
*License along with the Mini Thread  Library; if not, see
*<https://www.gnu.org/licenses/>.
*/
#include "mn_config.hpp"
#include "net/mn_basic_ip6_endpoint.hpp"

#if MN_THREAD_CONFIG_NET_IPADDRESS6_ENABLE == MN_THREAD_CONFIG_YES


namespace mn {
	namespace net {
		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const uint16_t& port)
			: base_type(MNNET_IPV6_ADDRESS_ANY, port) { }

		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const basic_ip6_address& ip, const uint16_t& port)
			: base_type(ip, port) { }
		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const basic_ip6_endpoint& pOther)
			: base_type(pOther.m_ipAdress, pOther.m_iPort) { }


		//-----------------------------------
		//  get_copy
		//-----------------------------------
		basic_endpoint* 	basic_ip6_endpoint::get_copy()  {
			return static_cast<basic_endpoint*>(new basic_ip6_endpoint(*this) );
		}
	}
}

#endif // MN_THREAD_CONFIG_NET_IPADDRESS6_ENABLE
