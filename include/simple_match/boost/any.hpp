// Copyright 2015 John R. Bandela
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef SIMPLE_MATCH_ANY_HPP_JRB_2015_09_11
#define SIMPLE_MATCH_ANY_HPP_JRB_2015_09_11
#include <boost/any.hpp>
#include "../simple_match.hpp"
namespace simple_match {

	// tagged_any

	template<class T>
	struct tagged_any :boost::any {
		template<class... A>
		tagged_any(A&& ...a) :boost::any{std::forward<A>(a)...} {}
	};

	namespace customization {
		template<>
		struct pointer_getter<boost::any> {
			template<class To, class T>
			static auto get_pointer(T&& t) {
				return boost::any_cast<To>(&t);
			}
		};
		template<class T>
		struct pointer_getter<tagged_any<T>> {
			template<class To, class T>
			static auto get_pointer(T&& t) {
				return boost::any_cast<To>(&t);
			}
		};


	}


}


#endif
