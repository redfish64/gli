///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2015 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/image.hpp
/// @date 2011-10-06 / 2013-01-12
/// @author Christophe Riccio
///
/// @defgroup core_image Image 
/// @ingroup core
///////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "storage.hpp"
#include "header.hpp"

namespace gli
{
	/// Image
	class image
	{
	public:
		typedef size_t size_type;
		typedef gli::format format_type;
		typedef storage::dim_type dim_type;
		typedef storage::data_type data_type;

		image();

		/// Allocate a new storage constructor
		explicit image(
			format_type const & Format,
			dim_type const & Dimensions);

		/// Reference an exiting storage constructor
		explicit image(
			storage const & Storage,
			format_type const & Format,
			size_type BaseLayer,
			size_type BaseFace,
			size_type BaseLevel);

		bool empty() const;
		format_type format() const;

		dim_type dimensions() const;

		size_type size() const;
		void * data();
		void const * data() const;

		template <typename genType>
		size_type size() const;
		template <typename genType>
		genType * data();
		template <typename genType>
		genType const * data() const;

		void clear();
		template <typename genType>
		void clear(genType const & Texel);
		template <typename genType>
		genType load(dim_type const & TexelCoord);
		template <typename genType>
		void store(dim_type const & TexelCoord, genType const & Data);

	private:
		data_type * const compute_data(size_type BaseLayer, size_type BaseFace, size_type BaseLevel) const;
		size_type compute_size(size_type Level) const;

		storage Storage;
		format_type const Format;
		size_type const BaseLevel;
		data_type * const Data;
		size_type const Size;
	};
}//namespace gli

#include "image.inl"
