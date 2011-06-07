////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2011 Bryce Lelbach
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#if !defined(HPX_2A00BD90_B331_44BC_AF02_06787ABC50E7)
#define HPX_2A00BD90_B331_44BC_AF02_06787ABC50E7

#include <hpx/hpx_fwd.hpp>
#include <hpx/lcos/future_value.hpp>
#include <hpx/runtime/components/client_base.hpp>
#include <hpx/runtime/agas/namespace/stubs/symbol.hpp>

namespace hpx { namespace agas 
{

// TODO: add error code parameters
template <typename Database, typename Protocol>
struct symbol_namespace :
    components::client_base<
        symbol_namespace<Database, Protocol>,
        stubs::symbol_namespace<Database, Protocol>
    >
{
    // {{{ nested types 
    typedef components::client_base<
        symbol_namespace<Database, Protocol>,
        stubs::symbol_namespace<Database, Protocol>
    > base_type; 

    typedef server::symbol_namespace<Database, Protocol> server_type;

    typedef typename server_type::response_type response_type;
    typedef typename server_type::symbol_type symbol_type;
    // }}}

    explicit symbol_namespace(naming::id_type const& id =
      naming::id_type(HPX_AGAS_SYMBOL_NS_MSB, HPX_AGAS_SYMBOL_NS_LSB,
                      naming::id_type::unmanaged))
      : base_type(id) {}

    ///////////////////////////////////////////////////////////////////////////
    // bind interface 
    lcos::future_value<response_type>
    bind_async(symbol_type const& key, naming::gid_type const& gid)
    { return this->base_type::bind_async(this->gid_, key, gid); }

    response_type bind(symbol_type const& key, naming::gid_type const& gid)
    { return this->base_type::bind(this->gid_, key, gid); }
    
    ///////////////////////////////////////////////////////////////////////////
    // rebind interface 
    lcos::future_value<response_type>
    rebind_async(symbol_type const& key, naming::gid_type const& gid)
    { return this->base_type::rebind_async(this->gid_, key, gid); }

    response_type rebind(symbol_type const& key, naming::gid_type const& gid)
    { return this->base_type::rebind(this->gid_, key, gid); }

    ///////////////////////////////////////////////////////////////////////////
    // resolve interface 
    lcos::future_value<response_type> resolve_async(symbol_type const& key)
    { return this->base_type::resolve_async(this->gid_, key); }
    
    response_type resolve(symbol_type const& key)
    { return this->base_type::resolve(this->gid_, key); }
 
    ///////////////////////////////////////////////////////////////////////////
    // unbind interface 
    lcos::future_value<response_type> unbind_async(symbol_type const& key)
    { return this->base_type::unbind_async(this->gid_, key); }
    
    response_type unbind(symbol_type const& key)
    { return this->base_type::unbind(this->gid_, key); }
};            

}}

#endif // HPX_2A00BD90_B331_44BC_AF02_06787ABC50E7

