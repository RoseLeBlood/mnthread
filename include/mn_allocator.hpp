/** 
 * This file is part of the Mini Thread Library (https://github.com/RoseLeBlood/MiniThread ).
 * Copyright (c) 2021 Amber-Sophia Schroeck
 *
 * The Mini Thread Library is free software; you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3, or (at your option) any later version.

 * The Mini Thread Library is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the Mini Thread  Library; if not, see
 * <https://www.gnu.org/licenses/>.  
*/

#ifndef _MINLIB_ALLOCATOR_H_
#define _MINLIB_ALLOCATOR_H_

#include "mn_allocator_system.hpp"
#include "mn_allocator_stack.hpp"
#include "mn_allocator_buffer.hpp"

#if MN_THREAD_CONFIG_BOARD ==  MN_THREAD_CONFIG_ESP32
#include "mn_allocator_caps.hpp"
#include "mn_allactor_multiheap.hpp"
#endif

namespace mn {
    namespace memory {

#if MN_THREAD_CONFIG_BOARD ==  MN_THREAD_CONFIG_ESP32 
        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_DEFAULT | MALLOC_CAP_8BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_internal_esp32_t = 
            basic_cap_allocator_esp32<T, cap_allocator_map::Default, cap_allocator_size::Size8Bit>;

        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_psram_esp32_t = 
            basic_cap_allocator_esp32<T, cap_allocator_map::SpiRam, cap_allocator_size::Size8Bit>;

        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_DEFAULT | MALLOC_CAP_32BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_internal32_esp32_t = 
            basic_cap_allocator_esp32<T, cap_allocator_map::Default, cap_allocator_size::Size32Bit>;

        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_SPIRAM | MALLOC_CAP_32BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_psram32_esp32_t = 
            basic_cap_allocator_esp32<T, cap_allocator_map::SpiRam, cap_allocator_size::Size32Bit>;

        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_DMA | MALLOC_CAP_32BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_internal_dma_esp32_t = 
            basic_cap_allocator_esp32<T, cap_allocator_map::DMA, cap_allocator_size::Size32Bit>;


        /**
         * @brief A esp32 cap allocator, config: MALLOC_CAP_DMA | MALLOC_CAP_32BIT 
         * @tparam T The value to allocate the allocator
         */
        template <typename T>
        using allocator_psram_dma_esp32_t = 
        basic_cap_allocator_esp32<T, cap_allocator_map::DMA, cap_allocator_size::Size32Bit>;

        /**
         * @brief Use the multiheap api as allocater
         * @tparam T        The type to allocate the allocator
         * @tparam TBytes   The size of the using buffer on the stack
         */
        template<typename T, unsigned long TBytes> 
        using multiheap_allocator_esp32_t = basic_multiheap_allocator_esp32<T, TBytes>;
#endif // MN_THREAD_CONFIG_BOARD ==  MN_THREAD_CONFIG_ESP32

        /**
         * @brief A basic allocator, use the basic alloc system from tde used libc 
         * @tparam T The value to allocate the allocator
         * @tparam sMaxSize The maximal size to use from memory, when 0 then no limit
         */
        template <typename T, int sMaxSize = 0>
        using allocator_system_t = basic_allocator_system<T, sMaxSize>;


#if MN_THREAD_CONFIG_ALLOCATOR_DEFAULT == MN_THREAD_CONFIG_ALLOCATOR_SYSTEM
        /**
         * @brief Use the basic_allocator_system as default allocator for this library 
         * @tparam T        The value to allocate the allocator
         * @tparam sMaxSize The maximal size to use from memory, when 0 then no limit
         */
        template <typename T, int sMaxSize = 0> 
        using default_allocator_t = allocator_system_t<T, sMaxSize>;
#endif

        /**
         * @brief Stack based allocator.
         * @note - operates on buffer of TBUFFERSIZE bytes of stack memory
         * @note - never frees memory
         * @note - cannot be copied
         * 
         * @tparam T                The value to allocate the allocator
         * @tparam TBUFFERSIZE      The size of the buffer
         */
        template<typename T, int TBUFFERSIZE>  
        using allocator_stack_t = basic_allocator_stack<T, TBUFFERSIZE>;

         /** 
         * @brief buffer based allocator.
         * @note - never frees memory
         * @note - cannot be copied
         * 
         * @author RoseLeBlood
         * @date 2021.02.21
         * @version 1.0
         */
        template<typename T> 
        using allocator_buffer_t = basic_allocator_buffer<T>;
    }
}