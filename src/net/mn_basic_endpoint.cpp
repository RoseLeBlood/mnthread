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
#include "net/mn_basic_endpoint.hpp"

namespace mn {
	namespace net {

		//-----------------------------------
		//  ip4_endpoint::basic_ip4_endpoint
		//-----------------------------------
		basic_ip4_endpoint::basic_ip4_endpoint(const uint16_t& port)
			: basic_ip4_endpoint(MNNET_IPV4_ADDRESS_ANY, port) { }


		//-----------------------------------
		//  ip4_endpoint::basic_ip4_endpoint
		//-----------------------------------
		basic_ip4_endpoint::basic_ip4_endpoint(const basic_ip4_address& ip, const uint16_t& port)
			:  m_iPort(8289), m_ipAdress(ip)  {
			if(port < 9999) m_iPort = port; else m_iPort = 0;
		}

		//-----------------------------------
		//  ip4_endpoint::basic_ip4_endpoint
		//-----------------------------------
		basic_ip4_endpoint::basic_ip4_endpoint(const basic_ip4_endpoint& pOther)
			: m_iPort(pOther.m_iPort), m_ipAdress(pOther.m_ipAdress) { }

		//-----------------------------------
		//  basic_ip4_endpoint::get_port()
		//-----------------------------------
		uint16_t basic_ip4_endpoint::get_port() {
			return m_iPort;
		}

		//-----------------------------------
		//  basic_ip4_endpoint::get_ip()
		//-----------------------------------
		basic_ip4_address basic_ip4_endpoint::get_ip() {
			return m_ipAdress;
		}

		//-----------------------------------
		//  basic_ip4_endpoint::set_port()
		//-----------------------------------
		void basic_ip4_endpoint::set_port(const uint16_t& port) {
			if(port < 9999) m_iPort = port;
		}

		//-----------------------------------
		//  basic_ip4_endpoint::is_broadcast()
		//-----------------------------------
		bool basic_ip4_endpoint::is_broadcast() {
			return m_ipAdress.is_broadcast();
		}

		//-----------------------------------
		//  basic_ip4_endpoint::is_loopback()
		//-----------------------------------
		bool basic_ip4_endpoint::is_loopback() {
			return m_ipAdress.is_loopback();
		}

		//-----------------------------------
		//  basic_ip4_endpoint::get_copy()
		//-----------------------------------
		basic_endpoint* 	basic_ip4_endpoint::get_copy()  {
			return static_cast<basic_endpoint*>(new basic_ip4_endpoint(*this) );
		}

		//-----------------------------------
		//  basic_ip4_endpoint::operator ==
		//-----------------------------------
		bool basic_ip4_endpoint::operator == (const basic_ip4_endpoint& pOther) {
			if(m_iPort != pOther.m_iPort) return false;
			return m_ipAdress == pOther.m_ipAdress;
		}

		//-----------------------------------
		//  basic_ip4_endpoint::operator !=
		//-----------------------------------
		bool basic_ip4_endpoint::operator != (const basic_ip4_endpoint& pOther) {
			if(m_iPort == pOther.m_iPort) return false;
			return m_ipAdress != pOther.m_ipAdress;
		}

		//-----------------------------------
		//  basic_ip4_endpoint::operator =
		//-----------------------------------
		basic_ip4_endpoint& basic_ip4_endpoint::operator = (const basic_ip4_endpoint& pOther) {
			m_iPort = pOther.m_iPort;
			m_ipAdress = pOther.m_ipAdress;
			return *this;
		}

#if MN_THREAD_CONFIG_NET_IPADDRESS6_ENABLE == MN_THREAD_CONFIG_YES

		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const uint16_t& port)
			: basic_ip6_endpoint(MNNET_IPV6_ADDRESS_ANY, port) { }

		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const basic_ip6_address& ip, const uint16_t& port)
			:  m_iPort(8289), m_ipAdress(ip)  {
			if(port < 9999) m_iPort = port; else m_iPort = 0;
		}
		//-----------------------------------
		//  basic_ip6_endpoint
		//-----------------------------------
		basic_ip6_endpoint::basic_ip6_endpoint(const basic_ip6_endpoint& pOther)
			: m_iPort(pOther.m_iPort), m_ipAdress(pOther.m_ipAdress) { }

		//-----------------------------------
		//  get_port
		//-----------------------------------
		uint16_t basic_ip6_endpoint::get_port() {
			return m_iPort;
		}
		//-----------------------------------
		//  get_ip
		//-----------------------------------
		basic_ip6_address basic_ip6_endpoint::get_ip() {
			return m_ipAdress;
		}

		//-----------------------------------
		//  set_port
		//-----------------------------------
		void basic_ip6_endpoint::set_port(const uint16_t& port) {
			if(port < 9999) m_iPort = port;
		}

		//-----------------------------------
		//  is_multicast
		//-----------------------------------
		bool basic_ip6_endpoint::is_multicast() {
			return m_ipAdress.is_multicast();
		}

		//-----------------------------------
		//  send_to
		//-----------------------------------
		bool basic_ip6_endpoint::is_loopback() {
			return m_ipAdress.is_loopback();
		}

		//-----------------------------------
		//  get_copy
		//-----------------------------------
		basic_endpoint* 	basic_ip6_endpoint::get_copy()  {
			return static_cast<basic_endpoint*>(new basic_ip6_endpoint(*this) );
		}

		//-----------------------------------
		//  operator ==
		//-----------------------------------
		bool basic_ip6_endpoint::operator == (const basic_ip6_endpoint& pOther) {
			if(m_iPort != pOther.m_iPort) return false;
			return m_ipAdress == pOther.m_ipAdress;
		}

		//-----------------------------------
		//  operator !=
		//-----------------------------------
		bool basic_ip6_endpoint::operator != (const basic_ip6_endpoint& pOther) {
			if(m_iPort == pOther.m_iPort) return false;
			return m_ipAdress != pOther.m_ipAdress;
		}

		//-----------------------------------
		//  operator =
		//-----------------------------------
		basic_ip6_endpoint& basic_ip6_endpoint::operator = (const basic_ip6_endpoint& pOther) {
			m_iPort = pOther.m_iPort;
			m_ipAdress = pOther.m_ipAdress;
			return *this;
		}
#endif // MN_THREAD_CONFIG_NET_IPADDRESS6_ENABLE
	}
}
